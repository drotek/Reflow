/******************************************************************************
*
* @file       Button.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for using the buttons
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
/*            Button_init()             */
/****************************************/         
void Button_init()
{
  pinMode(UP, INPUT);
  pinMode(OK, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(DOWN, INPUT);
  
  digitalWrite(UP, HIGH);
  digitalWrite(OK, HIGH);
  digitalWrite(RIGHT, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(DOWN, HIGH);
}
   
         


