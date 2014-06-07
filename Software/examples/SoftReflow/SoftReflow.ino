/******************************************************************************
*
* @file       SoftReflow.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Main program
*
*             Products: http://www.drotek.fr/shop/en/5-controleur-refusion
*             Discussions: http://www.drotek.fr/forum
*
* @license    The GNU Public License (GPL) Version 3
*
* @Changelog  xx-xx-2014 - ...
*
*****************************************************************************/

/****************************************/
/*        Include Header Files          */
/****************************************/
#include <glcd.h>
#include <glcd_Buildinfo.h>
#include <glcd_Config.h>
#include "fonts/allFonts.h"
#include "bitmaps/allBitmaps.h" 
#include <EEPROM.h>
#include "defines.h"


/****************************************/
/*              Variables               */
/****************************************/
//======GLCD=======
Image_t icon;
      

//=====VARIANTS======
int soak_temp = 0;
int soak_time = 0;
int preheat_temp = 0 ;
int preheat_deg_max = 0;
int reflow_temp = 0;
int reflow_time = 0;
int cooling_temp = 0;
int cooling_deg_max = 0;


/****************************************/
/*                SETUP                 */
/****************************************/

void setup(){
  
  /* Open a serial communication */ 
  Serial.begin(9600);
  
  /* Initialization of all devices */  
  MAX6675_init();
  Button_init();
  Relay_init();
  Fan_init();
  Buzzer_init();  
  GLCD.Init();
  
  /* Configuration of LCD */ 
  icon = ArduinoIcon64x64;
  GLCD.ClearScreen(); 
  GLCD.SelectFont(System5x7, BLACK);
   
  // Check if it's the first boot  
  CheckFirstBoot();

  //Transferts EEPROM values to RAM
  EEPROMtoRAM();  
   
  //intro(10); // Introduction
}


/****************************************/
/*             Main Loop                */
/****************************************/
void loop(){
  
    // ============== MAIN_MENU==============
begin:
    GLCD.ClearScreen();
    menuP1();
    pause(250);
    while (digitalRead(OK) != 0 && digitalRead(DOWN) != 0);
    
    if (digitalRead(OK) != 1){
      
      GLCD.ClearScreen();
      
      /** Begin of reflow steps **/
      preheating();
      soaking();
      reflow();
      cooling();
      
      delay(250);
      while (digitalRead(OK) != 0);
      GLCD.ClearScreen();
      goto begin; 
    }       
    else{
      GLCD.ClearScreen();
      menuP2();
    }
      
    while(digitalRead(OK) != 0 && digitalRead(UP) != 0);
    if (digitalRead(UP) != 1){
      goto begin;
    }
    delay(250);
        
    //=================== SETTINGS =======================
    if (BOOT_VALUE != 31){ //  Next is not to do in first
         
Preheat_Temp: 
            setPreheat();
            GLCD.CursorToXY(13,10);
            GLCD.print("Preheat Deg max/s");
            GLCD.CursorToXY(36,40);
            GLCD.print("<");
            GLCD.CursorToXY(88,40);
            GLCD.print(">");
            while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(UP) != 0);
              if (digitalRead(RIGHT) != 1){ preheat_temp = preheat_temp+1;  goto Preheat_Temp; } 
              if (digitalRead(LEFT) != 1){  preheat_temp = preheat_temp-1; goto Preheat_Temp; }
              if (digitalRead(UP) != 1){delay(400); GLCD.ClearScreen(); goto Preheat_Deg_max;}
              if (digitalRead(OK) != 1){delay(400);
              goto Floor1;}  
            
Preheat_Deg_max: 
            setPreheat();
            GLCD.CursorToXY(26,10);
            GLCD.print("Preheat degrees");
            GLCD.CursorToXY(36,30);
            GLCD.print("<");
            GLCD.CursorToXY(88,30);
            GLCD.print(">");
            while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(DOWN) != 0);
              if (digitalRead(RIGHT) != 1){ preheat_deg_max = preheat_deg_max+1;  goto Preheat_Deg_max; } 
              if (digitalRead(LEFT) != 1){  preheat_deg_max = preheat_deg_max-1; goto Preheat_Deg_max; } 
              if (digitalRead(DOWN) != 1){delay(400); GLCD.ClearScreen(); goto Preheat_Temp;}
              if (digitalRead(OK) != 1){delay(400);
              goto Floor1;}   
Soak_Temp:     
            setSoak();
            GLCD.CursorToXY(26,10);
            GLCD.print("Soak degrees");
            GLCD.CursorToXY(36,40);
            GLCD.print("<");
            GLCD.CursorToXY(88,40);
            GLCD.print(">");
            while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(UP) != 0);
              if (digitalRead(RIGHT) != 1){ soak_temp = soak_temp+1;  goto Soak_Temp; } // increases soak_temp at each time of RIGHT button is pressed
              if (digitalRead(LEFT) != 1){  soak_temp = soak_temp-1; goto Soak_Temp; } // decrease soak_temp at each time of LEFT button is pressed
              if (digitalRead(UP) != 1){delay(400); GLCD.ClearScreen(); goto Soak_Time;} // switch to next value
              if (digitalRead(OK) != 1){delay(400); goto Floor1;}

Soak_Time:     
            setSoak();
            GLCD.CursorToXY(26,10);
            GLCD.print("Soak time");
            GLCD.CursorToXY(36,30);
            GLCD.print("<");
            GLCD.CursorToXY(88,30);
            GLCD.print(">");
            while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(DOWN) != 0);
              if (digitalRead(RIGHT) != 1){ soak_time = soak_time+1;  goto Soak_Time; }
              if (digitalRead(LEFT) != 1){  soak_time = soak_temp-1; goto Soak_Time; } 
              if (digitalRead(DOWN) != 1){delay(400); GLCD.ClearScreen(); goto Soak_Temp;}
              if (digitalRead(OK) != 1){delay(400);
              goto Floor1;}
              
Reflow_Temp:
            setReflow();
            GLCD.CursorToXY(26,10);
            GLCD.print("Reflow degrees");
            GLCD.CursorToXY(36,40);
            GLCD.print("<");
            GLCD.CursorToXY(88,40);
            GLCD.print(">");
            while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(UP) != 0);
              if (digitalRead(RIGHT) != 1){ reflow_temp = reflow_temp+1;  goto Reflow_Temp; } 
              if (digitalRead(LEFT) != 1){  reflow_temp = reflow_temp-1; goto Reflow_Temp; }
              if (digitalRead(UP) != 1){delay(400); GLCD.ClearScreen(); goto Reflow_Time;}
              if (digitalRead(OK) != 1){delay(400);
              goto Floor1;}
              
Reflow_Time:   
            setReflow();
            GLCD.CursorToXY(26,10);
            GLCD.print("Reflow time");
            GLCD.CursorToXY(36,30);
            GLCD.print("<");
            GLCD.CursorToXY(88,30);
            GLCD.print(">");
            while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(DOWN) != 0);
              if (digitalRead(RIGHT) != 1){ reflow_time = reflow_time+1;  goto Reflow_Time; } 
              if (digitalRead(LEFT) != 1){  reflow_time = reflow_time-1; goto Reflow_Time; } 
              if (digitalRead(DOWN) != 1){delay(400); GLCD.ClearScreen(); goto Reflow_Temp;}
              if (digitalRead(OK) != 1){delay(400);
              goto Floor1;}
              
Cooling_Temp:  
               setCooling();
               GLCD.CursorToXY(13,10);
               GLCD.print("Cooling Deg max/s");
               GLCD.CursorToXY(36,40);
               GLCD.print("<");
               GLCD.CursorToXY(88,40);
               GLCD.print(">");
               while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(UP) != 0 );
                  if (digitalRead(RIGHT) != 1){ cooling_temp = cooling_temp+1;  goto Cooling_Temp; }
                  if (digitalRead(LEFT) != 1){  cooling_temp = cooling_temp-1; goto Cooling_Temp; }
                  if (digitalRead(UP) != 1){delay(400); GLCD.ClearScreen(); goto Cooling_Deg_max;}
                  if (digitalRead(OK) != 1){delay(400); goto Floor1;}
            
Cooling_Deg_max:  
               setCooling();
               GLCD.CursorToXY(26,10);
               GLCD.print("Cooling degrees");
               GLCD.CursorToXY(36,30);
               GLCD.print("<");
               GLCD.CursorToXY(88,30);
               GLCD.print(">");
               while( digitalRead(OK) != 0 && digitalRead(RIGHT) != 0 && digitalRead(LEFT) != 0 && digitalRead(DOWN) != 0 );
                  if (digitalRead(RIGHT) != 1){ cooling_deg_max = cooling_deg_max+1;  goto Cooling_Deg_max; }
                  if (digitalRead(LEFT) != 1){  cooling_deg_max = cooling_deg_max-1; goto Cooling_Deg_max; }
                  if (digitalRead(DOWN) != 1){delay(400); GLCD.ClearScreen(); goto Cooling_Temp;}
                  if (digitalRead(OK) != 1){delay(400); goto Floor1;}

}
              
//====================== Selecting one by one the settings menu's options =========================
Floor1:
        GLCD.ClearScreen();
        settings2select1();
        while(digitalRead(OK) != 0 && digitalRead(DOWN) != 0 && digitalRead(UP) != 0);
          if (digitalRead(OK) != 1){delay(400); goto Preheat_Temp;}
          if (digitalRead(UP) != 1){ delay(400); goto Floor5;}
        delay(400);
        
Floor2:    GLCD.ClearScreen();
            settings2select2();
            while(digitalRead(OK) != 0 && digitalRead(DOWN) != 0 && digitalRead(UP) != 0 );
              if (digitalRead(OK) != 1){ delay(400); goto Soak_Temp;}
              if (digitalRead(UP) != 1){delay(400); goto Floor1;}
            delay(400);
            
Floor3:        GLCD.ClearScreen();
                settings2select3();
                while(digitalRead(OK) != 0 && digitalRead(DOWN) != 0 && digitalRead(UP) != 0 );
                  if (digitalRead(UP) != 1){delay(400); goto Floor2; }
                  if (digitalRead(OK) != 1){delay(400); goto Reflow_Temp;}
                delay(400);
                
Floor4:            GLCD.ClearScreen();
                    settings2select4();
                    while(digitalRead(OK) != 0 && digitalRead(DOWN) != 0 && digitalRead(UP) != 0 );
                      if (digitalRead(UP) != 1){delay(400); goto Floor3; }
                      if (digitalRead(OK) != 1){delay(400); goto Cooling_Temp;}
                    delay(400);
                    
Floor5:                GLCD.ClearScreen();
                        settings2select5();
                        while(digitalRead(OK) != 0 && digitalRead(UP) != 0 && digitalRead(DOWN) != 0);
                          if (digitalRead(UP) != 1){ delay(400); goto Floor4; }
                          if (digitalRead(DOWN) != 1){ delay(400); goto Floor1;}
                          if (digitalRead(OK) != 1){     
                        GLCD.ClearScreen();
                        GLCD.CursorToXY(20,35);
                        //*****************************************************************************************
                        GLCD.print("Saving values..");// Save the value in EEPROM and return to the precedent menu
                        RAMtoEEPROM();
                        delay(1000);
                        //*****************************************************************************************
                        goto begin;}}


