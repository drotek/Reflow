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
  
  /* Confi of LCD */ 
  GLCD.ClearScreen(); 
  GLCD.SelectFont(System5x7, BLACK); 
}
  

/****************************************/
/*             Main Loop                */
/****************************************/
void loop(){
  
  GLCD.CursorToXY(2,5);
  GLCD.print("Hello, welcome to the Reflow controller test, open the graphic interface please, OK to continue");
  while(digitalRead(OK) != 0);
  
  /**** Test of EEPROM ****/
  EEPROM_test();
  
  /** Test of LED and fan outputs **/ 
  Fan_test();
 
  /** Test of LED and relay outputs **/ 
  Relay_test();
  
  /**** Test of buzzer ****/ 
  Buzzer_test();
  
  /*** Test of MAX6675 IC ***/ 
  MAX6675_test();
   
  /* Test of USB communication */ 
  Serial_test();
  
  
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("End of test");
  delay(3000);
}
