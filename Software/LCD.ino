/******************************************************************************
*
* @file       LCD.ino
* @author     E.Esquirol, http://www.drotek.fr Copyright (C) 2014.
* @brief      Library for using the LCD
*
*             Products: http://www.drotek.fr/shop/en/5-controleur-refusion
*             Discussions: http://www.drotek.fr/forum
*
* @license    The GNU Public License (GPL) Version 3
*
* @Changelog  xx-xx-2014 - ...
*
*****************************************************************************/


void intro(int timer) {
  GLCD.DrawCircle( 15, 30, 5); 
  GLCD.DrawCircle( 112, 30, 5);
  GLCD.DrawRoundRect(2,45,GLCD.Width-5,15,5);
  GLCD.DrawBitmap(icon, 32,0);
  GLCD.CursorToXY(30,50);
  GLCD.print("Firmware V");
  GLCD.CursorToXY(92,50);
  GLCD.print(VERSION, DEC);
  GLCD.CursorToXY(29,32);
  GLCD.print("With Arduino");
  GLCD.CursorToXY(0,0);
  countdown(4);
  delay(timer);
  GLCD.ClearScreen();
}

void menu(){
  GLCD.DrawRect(GLCD.CenterX - 11, 3, 26, 10); // posX , posY , widht , height 
  GLCD.DrawRect(GLCD.CenterX - 12, 2, 28, 12); // double 
  GLCD.CursorToXY(55,5);
  GLCD.print("MENU");
  GLCD.CursorToXY(12,25);
  GLCD.print("Start");
  GLCD.CursorToXY(12,35);
  GLCD.print("Settings");
}

void menuP1(){

  menu();
  GLCD.CursorToXY(2,25);
  GLCD.print(">");
}

void menuP2(){

  menu();
  GLCD.CursorToXY(2,35);
  GLCD.print(">");
}

void pause(int timer){
  delay(timer);
}

void drawSpinner(byte pos, byte x, byte y) {
  switch(pos % 8) {
    case 0 : GLCD.DrawLine( x, y-8, x, y+8);      pause(10);
    case 1 : GLCD.DrawLine( x+3, y-7, x-3, y+7);  pause(10); 
    case 2 : GLCD.DrawLine( x+6, y-6, x-6, y+6);  pause(10);
    case 3 : GLCD.DrawLine( x+7, y-3, x-7, y+3);  pause(10);
    case 4 : GLCD.DrawLine( x+8, y, x-8, y);      pause(10);
    case 5 : GLCD.DrawLine( x+7, y+3, x-7, y-3);  pause(10);
    case 6 : GLCD.DrawLine( x+6, y+6, x-6, y-6);  pause(10);
    case 7 : GLCD.DrawLine( x+3, y+7, x-3, y-7);  pause(10);
    GLCD.FillRect( GLCD.CenterX + GLCD.CenterX/2-8 ,GLCD.CenterY + GLCD.CenterY/2 -8,16,16, WHITE);
}}
void countdown(int count){
    while(count--){  // do countdown  
     GLCD.CursorToXY(0,0);   // first column, second row (offset is from 0)
     GLCD.PutChar(count + '0');
     delay(1000);}}
     
     
void settings() {
  GLCD.ClearScreen();
  GLCD.CursorToXY(10,28);
  GLCD.print("You enter Settings");}
  
void set() {
  GLCD.ClearScreen();
  GLCD.CursorToXY(10,40);
  GLCD.print("OK to return Home");
  GLCD.CursorToXY(10,10);
  GLCD.print("You enter Start");
  delay(1000);

}

  
void temp(){
            GLCD.CursorToXY(16,15);
            GLCD.print("It's");
            GLCD.CursorToXY(46,25);
            GLCD.print("degrees");
            GLCD.CursorToXY(0,46);
            GLCD.print("keep OK to return");
            GLCD.CursorToXY(0,0);
            GLCD.print("Are you cold? :)");
            delay(1000);
            pause(500);}


         
void menuSoak (){
            GLCD.CursorToXY(26,10);
            GLCD.print("Soak degrees");
            GLCD.CursorToXY(40,40);
            GLCD.print("<");
            GLCD.CursorToXY(88,40);
            GLCD.print(">");}
            
void settings2 (){
  GLCD.DrawRect(GLCD.CenterX - 26, 3, 50, 10); // posX , posY , widht , height 
  GLCD.DrawRect(GLCD.CenterX - 27, 2, 52, 12); // double 
  GLCD.CursorToXY(40,5);
  GLCD.print("SETTINGS");
  GLCD.CursorToXY(12,15);
  GLCD.print("Soak");
  GLCD.CursorToXY(12,25);
  GLCD.print("Preheat");
  GLCD.CursorToXY(12,35);
  GLCD.print("Reflow");
  GLCD.CursorToXY(12,45);
  GLCD.print("Cooling");
  GLCD.CursorToXY(12,55);
  GLCD.print("Back");}
  
  void settings2select1(){
  settings2();
  GLCD.CursorToXY(2,15);
  GLCD.print(">");}
  
  void settings2select2(){
  settings2();
  GLCD.CursorToXY(2,25);
  GLCD.print(">");}
 
  void settings2select3(){
  settings2();
  GLCD.CursorToXY(2,35);
  GLCD.print(">");}
  
  void settings2select4(){
  settings2();
  GLCD.CursorToXY(2,45);
  GLCD.print(">");}
  
  void settings2select5(){
  settings2();
  GLCD.CursorToXY(2,55);
  GLCD.print(">");}
  
  void save(){
  GLCD.CursorToXY(50,35);
  GLCD.print("Saving value..");
  delay(750);
  //goto Sfloor1;
}
