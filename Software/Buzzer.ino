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

