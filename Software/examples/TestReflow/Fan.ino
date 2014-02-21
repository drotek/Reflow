/******************************************************************************
*
* @file       Fan.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for switching fan
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
/*            Fan_init()                */
/****************************************/         
void Fan_init()
{
  digitalWrite(FAN, LOW);
  pinMode(FAN, OUTPUT);
  
}
   
         
/****************************************/
/*            Fan_on()                  */
/****************************************/         
void Fan_on()
{
  digitalWrite(FAN, HIGH);
}


/****************************************/
/*            Fan_off()                 */
/****************************************/         
void Fan_off()
{
  digitalWrite(FAN, LOW);
}
