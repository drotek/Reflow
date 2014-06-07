/******************************************************************************
*
* @file       Serial.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for testing USB communication
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
/*            Serial_test()             */
/****************************************/         
void Serial_test()
{
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
  
}

