/******************************************************************************
*
* @file       EEPROM.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for using the EEPROM
*
*             Products: http://www.drotek.fr/shop/en/5-controleur-refusion
*             Discussions: http://www.drotek.fr/forum
*
* @license    The GNU Public License (GPL) Version 3
*
* @Changelog  xx-xx-2014 - ...
*
*****************************************************************************/

int value = 200;
int address = 10;


/****************************************/
/*            EEPROM_test()             */
/****************************************/         
void EEPROM_test()
{
  EEPROM.write(address, value);
    
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("Press left button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test EEPROM");
  while(digitalRead(LEFT) != 0);
  GLCD.ClearScreen();
  delay(100);
  
  value = EEPROM.read(address);
  
  if (EEPROM.read(address) == value){
    GLCD.CursorToXY(2,25);
    GLCD.print("EEPROM OK");
  }
  else{
    GLCD.CursorToXY(2,25);
    GLCD.print("EEPROM ERROR");
  }
  
  delay(4000);
  GLCD.ClearScreen();
}

