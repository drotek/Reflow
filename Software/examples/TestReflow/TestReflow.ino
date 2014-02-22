/******************************************************************************
*
* @file       testReflow.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Source file for testing the reflow oven controller
*
*             Products: http://www.drotek.fr/shop/en/5-controleur-refusion
*             Discussions: http://www.drotek.fr/forum
*
* @license    The GNU Public License (GPL) Version 3
*
* @Changelog  xx-xx-2014 - ....
*
*****************************************************************************/


/****************************************/
/*        Include Header Files          */
/****************************************/
#include <glcd.h>
#include <glcd_Buildinfo.h>
#include <glcd_Config.h>
#include <EEPROM.h>
#include "fonts/allFonts.h"
#include "bitmaps/allBitmaps.h" 
#include "define.h"


/****************************************/
/*              Variables               */
/****************************************/
Image_t icon;

unsigned long startMillis;
unsigned int  loops = 0;
unsigned int  iter = 0;
int  theDelay = 20; 
int val = 0;
                 
float temperature = 0.0; 
int TEMP = 200;


/****************************************/
/*                SETUP                 */
/****************************************/
void setup(){
  
  /* Initialization of all devices */  
  MAX6675_init();
  Button_init();
  Relay_init();
  Fan_init();
  Buzzer_init();  
  GLCD.Init();
  
  EEPROM.write(0,TEMP);
  
  icon = ArduinoIcon64x64;
  GLCD.ClearScreen(); 
  GLCD.SelectFont(System5x7, BLACK);
  delay(100);
  //intro(10);
  Serial.begin(9600);
}
  

/****************************************/
/*             Main Loop                */
/****************************************/
void loop(){
  
  TEMP = TEMP + 10;
begin:
  GLCD.CursorToXY(2,5);
  GLCD.print("Hello, welcome to the Reflow test v1, open the graphic interface please, OK to continue");
  while(digitalRead(OK) != 0);
  
  /**** Test of EEPROM ****/
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("Press left button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test EEPROM");
  while(digitalRead(LEFT) != 0);
  GLCD.ClearScreen();
  GLCD.print(TEMP);
  delay(100);
  GLCD.ClearScreen();
  
  if (TEMP = 210){
    GLCD.CursorToXY(2,25);
    GLCD.print("EEPROM OK");
  }
  
  if (TEMP != 210){
    GLCD.CursorToXY(2,25);
    GLCD.print("EEPROM ERROR");
    delay(5000);
  }
  
  delay(1000);
  GLCD.ClearScreen();
  
  /** Test of LED and fan outputs **/ 
  Fan_test();
 
  /** Test of LED and relay outputs **/ 
  Relay_test();
  
  /**** Test of buzzer ****/ 
  Buzzer_test();
  
  /*** Test of MAX6675 IC ***/ 
  MAX6675_test();
  
  
  /* Test of USB communication */ 
  GLCD.CursorToXY(2,25);
  GLCD.print("Press OK button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test USB port");
  while(digitalRead(OK) != 0);
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,35);
  GLCD.print("Check the monitor");
  delay(1000);
    
  for (int i=0; i <= 5; i++){
    Serial.print("It is work!      ");
    delay(500);
  }
  
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("End of test");
  delay(3000);
}
