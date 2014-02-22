/******************************************************************************
*
* @file       Buzzer.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for using the buzzer
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
/*            Buzzer_init()             */
/****************************************/         
void Buzzer_init()
{
  digitalWrite(BUZZER, LOW);
  pinMode(BUZZER, OUTPUT);   
}
   
         
/****************************************/
/*            Buzzer_on()               */
/****************************************/         
void Buzzer_on()
{
  digitalWrite(BUZZER, HIGH);
}


/****************************************/
/*            Buzzer_off()              */
/****************************************/         
void Buzzer_off()
{
  digitalWrite(BUZZER, LOW);
}


/****************************************/
/*            Buzzer_test()             */
/****************************************/         
void Buzzer_test()
{
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("Press right button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test Buzzer");
  while(digitalRead(RIGHT) != 0);
  
  GLCD.ClearScreen();
  Buzzer_on();
  delay(3000);
  Buzzer_off();
  GLCD.ClearScreen();
}

