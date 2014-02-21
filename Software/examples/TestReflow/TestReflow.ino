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
* @Changelog  xx-xx-2014 - ...
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
/*           Initialization             */
/****************************************/
void setup(){
  
  
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
  GLCD.CursorToXY(2,25);
  GLCD.print("Press right button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test FAN");
  while(digitalRead(RIGHT) != 0);
  GLCD.ClearScreen();
  digitalWrite(FAN, HIGH);
  delay(3000);
  digitalWrite(FAN, LOW);
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("Press TOP button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test RELAY");
  while(digitalRead(UP) != 0);
  GLCD.ClearScreen();
  digitalWrite(RELAY, HIGH);
  delay(3000);
  digitalWrite(RELAY, LOW);
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("Press DOWN button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test MAX6675");
  while(digitalRead(DOWN) != 0);
  GLCD.ClearScreen();
  
  for (int i=0; i <= 30; i++){
    temperature = MAX6675_read_temp(5);
    GLCD.CursorToXY(2,25);
    GLCD.print("Are you cold? :)");
    GLCD.CursorToXY(2,45);
    GLCD.print(temperature);
    delay(250);
    GLCD.ClearScreen();
  }
  
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
