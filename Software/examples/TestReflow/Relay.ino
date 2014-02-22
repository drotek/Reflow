/******************************************************************************
*
* @file       Relay.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for switching the relay
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
/*            Relay_init()              */
/****************************************/         
void Relay_init()
{
  digitalWrite(RELAY, LOW);
  pinMode(RELAY, OUTPUT);
}
   

/****************************************/
/*            Relay_on()                */
/****************************************/         
void Relay_on()
{
  digitalWrite(RELAY, HIGH);
}


/****************************************/
/*            Relay_off()               */
/****************************************/         
void Relay_off()
{
  digitalWrite(RELAY, LOW);
}


/****************************************/
/*            Relay_test()              */
/****************************************/         
void Relay_test()
{
  GLCD.ClearScreen();
  GLCD.CursorToXY(2,25);
  GLCD.print("Press TOP button");
  GLCD.CursorToXY(2,35);
  GLCD.print("to test RELAY");
  while(digitalRead(UP) != 0);
  
  GLCD.ClearScreen();
  Relay_on();
  delay(3000);
  Relay_off();
  GLCD.ClearScreen();
}
