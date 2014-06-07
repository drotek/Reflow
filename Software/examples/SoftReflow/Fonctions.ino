
void intro(int timer) { // Introduction with version of firmware
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

void menu(){ // The main MENU
  GLCD.DrawRect(GLCD.CenterX - 11, 3, 26, 10); // posX , posY , widht , height 
  GLCD.DrawRect(GLCD.CenterX - 12, 2, 28, 12); // double 
  GLCD.CursorToXY(55,5);
  GLCD.print("MENU");
  GLCD.CursorToXY(12,25);
  GLCD.print("Start");
  GLCD.CursorToXY(12,35);
  GLCD.print("Settings");
}

void menuP1(){ // Select the first option in the MENU

  menu();
  GLCD.CursorToXY(2,25);
  GLCD.print(">");
}

void menuP2(){ // // Select the second option in the MENU

  menu();
  GLCD.CursorToXY(2,35);
  GLCD.print(">");
}

void pause(int timer){
  delay(timer);
}

void drawSpinner(byte pos, byte x, byte y) { // To draw a spinner
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
  
void set() {
  GLCD.ClearScreen();
  GLCD.CursorToXY(10,40);
  GLCD.print("OK to return Home");
  GLCD.CursorToXY(10,10);
  GLCD.print("You enter Start");
  delay(1000);

}             
            
void settings2 (){ // MENU STETTINGS
  GLCD.DrawRect(GLCD.CenterX - 26, 3, 50, 10); // posX , posY , widht , height 
  GLCD.DrawRect(GLCD.CenterX - 27, 2, 52, 12); // double 
  GLCD.CursorToXY(40,5);
  GLCD.print("SETTINGS");
  GLCD.CursorToXY(12,15);
  GLCD.print("Preheat");
  GLCD.CursorToXY(12,25);
  GLCD.print("Soak");
  GLCD.CursorToXY(12,35);
  GLCD.print("Reflow");
  GLCD.CursorToXY(12,45);
  GLCD.print("Cooling");
  GLCD.CursorToXY(12,55);
  GLCD.print("Back");}
  
//Each select of the settings MENU
  
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
  GLCD.print(">");
}


   //include all values pre-saved on EEPROM into RAM  
void EEPROMtoRAM(){
   soak_temp = EEPROM.read(SOAK_TEMP_MSB_ADDR) + EEPROM.read(SOAK_TEMP_LSB_ADDR);
   soak_time = EEPROM.read(SOAK_TIME_MSB_ADDR) + EEPROM.read(SOAK_TIME_LSB_ADDR);
   
   preheat_temp = EEPROM.read(PREHEAT_TEMP_MSB_ADDR) + EEPROM.read(PREHEAT_TEMP_LSB_ADDR);
   preheat_deg_max = EEPROM.read(PREHEAT_DEG_MAX_MSB_ADDR) + EEPROM.read(PREHEAT_DEG_MAX_LSB_ADDR);
   
   reflow_temp = EEPROM.read(REFLOW_TEMP_MSB_ADDR) + EEPROM.read(REFLOW_TEMP_LSB_ADDR);
   reflow_time = EEPROM.read(REFLOW_TIME_MSB_ADDR) + EEPROM.read(REFLOW_TIME_LSB_ADDR);
   
   cooling_temp = EEPROM.read(COOLING_TEMP_MSB_ADDR) + EEPROM.read(COOLING_TEMP_LSB_ADDR);
   cooling_deg_max = EEPROM.read(COOLING_DEG_MAX_MSB_ADDR) + EEPROM.read(COOLING_DEG_MAX_LSB_ADDR);
  }
   
   // Save the values into EEPROM
void RAMtoEEPROM(){
    if(soak_temp > 255){
      EEPROM.write(SOAK_TEMP_LSB_ADDR,255); soak_temp >> 8;
      EEPROM.write(SOAK_TEMP_MSB_ADDR,soak_temp);}
    else
      EEPROM.write(SOAK_TEMP_LSB_ADDR,soak_temp);
      EEPROM.write(SOAK_TEMP_MSB_ADDR,0);
      
    if(soak_time > 255){
      EEPROM.write(SOAK_TIME_LSB_ADDR,255); soak_time >> 8;
      EEPROM.write(SOAK_TIME_MSB_ADDR,soak_time);}
    else
      EEPROM.write(SOAK_TIME_LSB_ADDR,soak_time);
      EEPROM.write(SOAK_TIME_MSB_ADDR,0);
      
    if(preheat_temp > 255){
      EEPROM.write(PREHEAT_TEMP_LSB_ADDR,255); preheat_temp >> 8;
      EEPROM.write(PREHEAT_TEMP_MSB_ADDR,preheat_temp);}
    else
      EEPROM.write(PREHEAT_TEMP_LSB_ADDR,preheat_temp);
      EEPROM.write(PREHEAT_TEMP_MSB_ADDR,0);
      
    if(preheat_deg_max > 255){
      EEPROM.write(PREHEAT_DEG_MAX_LSB_ADDR,255); preheat_deg_max >> 8;
      EEPROM.write(PREHEAT_DEG_MAX_MSB_ADDR,preheat_deg_max);}
    else
      EEPROM.write(PREHEAT_DEG_MAX_LSB_ADDR,preheat_deg_max);
      EEPROM.write(PREHEAT_DEG_MAX_MSB_ADDR,0);
      
    if(reflow_temp > 255){
      EEPROM.write(REFLOW_TEMP_LSB_ADDR,255); reflow_temp >> 8;
      EEPROM.write(REFLOW_TEMP_MSB_ADDR,reflow_temp);}
    else
      EEPROM.write(REFLOW_TEMP_LSB_ADDR,reflow_temp);
      EEPROM.write(REFLOW_TEMP_MSB_ADDR,0);
      
    if(reflow_time > 255){
      EEPROM.write(REFLOW_TIME_LSB_ADDR,255); reflow_time >> 8;
      EEPROM.write(REFLOW_TIME_MSB_ADDR,reflow_time);}
    else
      EEPROM.write(REFLOW_TIME_LSB_ADDR,reflow_time);
      EEPROM.write(REFLOW_TIME_MSB_ADDR,0);
      
    if(cooling_temp > 255){
      EEPROM.write(COOLING_TEMP_LSB_ADDR,255); cooling_temp >> 8;
      EEPROM.write(COOLING_TEMP_MSB_ADDR,cooling_temp);}
    else
      EEPROM.write(COOLING_TEMP_LSB_ADDR,cooling_temp);
      EEPROM.write(COOLING_TEMP_MSB_ADDR,0);
      
    if(cooling_deg_max > 255){
      EEPROM.write(COOLING_DEG_MAX_LSB_ADDR,255); cooling_deg_max >> 8;
      EEPROM.write(COOLING_DEG_MAX_MSB_ADDR,cooling_deg_max);}
    else
      EEPROM.write(COOLING_DEG_MAX_LSB_ADDR,cooling_deg_max);
      EEPROM.write(COOLING_DEG_MAX_MSB_ADDR,0);
    }


void CheckFirstBoot(){
  
    if (EEPROM.read(BOOT_ADDR)!= BOOT_VALUE){
      
      GLCD.ClearScreen();
      GLCD.CursorToXY(1,10);
      GLCD.print("It's the FirstBoot!!!");
      GLCD.CursorToXY(1,30);
      GLCD.print("Writing default values in EEprom...");
    
      EEPROM.write(SOAK_TEMP_LSB_ADDR,SOAK_TEMP);
      EEPROM.write(SOAK_TEMP_MSB_ADDR,0);
    
      EEPROM.write(SOAK_TIME_LSB_ADDR,SOAK_TIME);
      EEPROM.write(SOAK_TIME_MSB_ADDR,0);
    
      EEPROM.write(PREHEAT_TEMP_LSB_ADDR,PREHEAT_TEMP);
      EEPROM.write(PREHEAT_TEMP_MSB_ADDR,0);
    
      EEPROM.write(PREHEAT_DEG_MAX_LSB_ADDR,PREHEAT_TEMP_MAX);
      EEPROM.write(PREHEAT_DEG_MAX_MSB_ADDR,0);
    
      EEPROM.write(REFLOW_TEMP_LSB_ADDR,REFLOW_TEMP);
      EEPROM.write(REFLOW_TEMP_MSB_ADDR,0);
    
      EEPROM.write(REFLOW_TIME_LSB_ADDR,REFLOW_TIME);
      EEPROM.write(REFLOW_TIME_MSB_ADDR,0);
    
      EEPROM.write(COOLING_TEMP_LSB_ADDR,COOLING_TEMP);
      EEPROM.write(COOLING_TEMP_MSB_ADDR,0);
    
      EEPROM.write(COOLING_DEG_MAX_LSB_ADDR,COOLING_TEMP_MAX);
      EEPROM.write(COOLING_DEG_MAX_MSB_ADDR,0);
    
      EEPROM.write(BOOT_ADDR,BOOT_VALUE);
    
      delay(10000);
    }
}
    
    
void setPreheat(){
          delay(75); // to modify the speed of the value's change
          GLCD.ClearScreen();
          GLCD.CursorToXY(56,40);
          GLCD.print(preheat_temp);
          GLCD.CursorToXY(56,30);
          GLCD.print(preheat_deg_max);
          GLCD.CursorToXY(58,55);
          GLCD.print("OK");
          GLCD.CursorToXY(95,40);
          GLCD.print("°C/sec");
          GLCD.CursorToXY(95,30);
          GLCD.print("sec");
}
              
              
void setSoak(){
          delay(75);
          GLCD.ClearScreen();
          GLCD.CursorToXY(56,40);
          GLCD.print(soak_temp);
          GLCD.CursorToXY(56,30);
          GLCD.print(soak_time);
          GLCD.CursorToXY(58,55);
          GLCD.print("OK");
          GLCD.CursorToXY(95,40);
          GLCD.print("°C");
          GLCD.CursorToXY(95,30);
          GLCD.print("sec");
}

void setReflow(){
          delay(75);
          GLCD.ClearScreen();
          GLCD.CursorToXY(56,40);
          GLCD.print(reflow_temp);
          GLCD.CursorToXY(56,30);
          GLCD.print(reflow_time);
          GLCD.CursorToXY(58,55);
          GLCD.print("OK");
          GLCD.CursorToXY(95,40);
          GLCD.print("°C");
          GLCD.CursorToXY(95,30);
          GLCD.print("sec");
}

void setCooling(){
          delay(75); 
          GLCD.ClearScreen();
          GLCD.CursorToXY(56,40);
          GLCD.print(cooling_temp);
          GLCD.CursorToXY(56,30);
          GLCD.print(cooling_deg_max);
          GLCD.CursorToXY(58,55);
          GLCD.print("OK");
          GLCD.CursorToXY(95,40);
          GLCD.print("°C/sec");
          GLCD.CursorToXY(95,30);
          GLCD.print("sec");
}

/*****************************************************
*               Steps of reflow                      *
*****************************************************/
/*******************************
*        Preheating            *
*******************************/
void preheating() 
{ 
  unsigned int temp_current = 0;
  unsigned int temp_consigne = 0;
  unsigned int time_current = 0;
  
  GLCD.ClearScreen();
  
  /* chauffage avec regulation (3°c/s max) */
  while (temp_current < preheat_temp) 
  { 
    time_current = seconde();    
    temp_current = MAX6675_read_temp(5);
    
     
     GLCD.CursorToXY(12,15);
     GLCD.print(seconde());
     GLCD.CursorToXY(50,15);
     GLCD.print("sec");    
     GLCD.CursorToXY(12,25);
     GLCD.print(MAX6675_read_temp(1));   
     GLCD.CursorToXY(50,25);
     GLCD.print("->");   
     GLCD.CursorToXY(65,25);
     GLCD.print(preheat_temp);    
     GLCD.CursorToXY(95,25);
     GLCD.print("°C/sec");
     GLCD.CursorToXY(12,35);
     GLCD.print("Preheating");   
    
    /* regulation de la temperature tous les 200ms */
    while (time_current == seconde()) 
    {     
        if ( (MAX6675_read_temp(5) < (temp_current + preheat_deg_max)) ) 
            Relay_on();    
        else 
            Relay_off();
        
        delay(200);
    }      
  } 
  Relay_off();
} 


/**************************
*      Soaking            *
**************************/
void soaking() 
{ 
  //unsigned int temp_current = 0;
  unsigned int time_current = 0;
  unsigned int countSecInit = 0;
  unsigned int temp_cible = (preheat_temp * 10); 
  
  GLCD.ClearScreen();
  countSecInit = seconde();        
  
  /* chauffage avec regulation  */
  while ((seconde() - countSecInit) < soak_time) 
  { 
    time_current = seconde();     
    temp_cible = temp_cible + ((soak_temp - preheat_temp) *10/ soak_time);
    
    GLCD.CursorToXY(12,15);
    GLCD.print(seconde());
    GLCD.CursorToXY(50,15);
    GLCD.print("sec");    
    GLCD.CursorToXY(12,25);
    GLCD.print(MAX6675_read_temp(1));   
    GLCD.CursorToXY(50,25);
    GLCD.print("->");   
    GLCD.CursorToXY(65,25);
    GLCD.print(soak_temp);    
    GLCD.CursorToXY(95,25);
    GLCD.print("°C/sec");
    GLCD.CursorToXY(12,35);
    GLCD.print("Soaking");
    
    /* regulation de la temperature tous les 200ms */
    while (time_current == seconde()) 
    {  
        if ((MAX6675_read_temp(5)*10) < temp_cible) 
            Relay_on();      
        else 
            Relay_off(); 
        
        delay(200);
    }     
  } 
}


/******************************
*          Reflow             *
******************************/
void reflow()
{
  unsigned int temp_current = 0;
  unsigned int countSecInit = 0; 
  
  GLCD.ClearScreen();
  
  /* Tant que la temperature de refusion n'est pas atteinte, on chauffe */
  while (temp_current < reflow_temp) 
  {
    temp_current = MAX6675_read_temp(5);    
    Relay_on();
 
    GLCD.CursorToXY(12,15);
    GLCD.print(seconde());
    GLCD.CursorToXY(50,15);
    GLCD.print("sec");    
    GLCD.CursorToXY(12,25);
    GLCD.print(MAX6675_read_temp(1));   
    GLCD.CursorToXY(50,25);
    GLCD.print("->");   
    GLCD.CursorToXY(65,25);
    GLCD.print(reflow_temp);    
    GLCD.CursorToXY(95,25);
    GLCD.print("°C/sec");
    GLCD.CursorToXY(12,35);
    GLCD.print("Reflow");   
    delay(200);    
  }
  
  countSecInit = seconde();        
    
  /* waiting for x secondes. Attente pour faire un petit palier */
  while ((seconde() - countSecInit) < reflow_time) 
  {
    temp_current = MAX6675_read_temp(5);
    
    GLCD.CursorToXY(12,15);
    GLCD.print(seconde());
    GLCD.CursorToXY(50,15);
    GLCD.print("sec");    
    GLCD.CursorToXY(12,25);
    GLCD.print(MAX6675_read_temp(1));   
    GLCD.CursorToXY(50,25);
    GLCD.print("->");   
    GLCD.CursorToXY(65,25);
    GLCD.print(reflow_temp);    
    GLCD.CursorToXY(95,25);
    GLCD.print("°C/sec");
    GLCD.CursorToXY(12,35);
    GLCD.print("Reflow: wait "); 
    GLCD.CursorToXY(70,35);
    GLCD.print(reflow_time);  
    delay(200); 
    
    if (temp_current < reflow_temp)
    {
      Relay_on(); 
    }
    else
      Relay_on(); 
      
    delay (200);
    
  }      
}


/*********************************
*            Cooling             *
*********************************/
void cooling() 
{ 
  unsigned int temp_current = 0;
  unsigned int temp_init = 0;
  unsigned int countSecInit = 0;
  unsigned int time_current = 0;
  
  temp_init = MAX6675_read_temp(5);  
  temp_current = temp_init;
  
  Relay_off(); 
  Buzzer_on();
  GLCD.ClearScreen();
  
  /* le buzzer sonne tant la porte n'est pas ouverte */
  while(temp_current >= (reflow_temp - (reflow_temp/20)))
  {
      temp_current = MAX6675_read_temp(5);
      Buzzer_on();
      
      GLCD.CursorToXY(12,15);
      GLCD.print(seconde());
      GLCD.CursorToXY(50,15);
      GLCD.print("sec");
      GLCD.CursorToXY(12,25);
      GLCD.print(MAX6675_read_temp(1));
      GLCD.CursorToXY(50,25);
      GLCD.print("°C/sec");
      GLCD.CursorToXY(12,35);
      GLCD.print("Open the door!!!!!!");   
      delay(200);
  }
  
  Buzzer_off();
  GLCD.ClearScreen();
  
  while (temp_current > cooling_temp)
  { 
    time_current = seconde();    
    temp_current = MAX6675_read_temp(5);
    
    GLCD.CursorToXY(12,15);
    GLCD.print(seconde());
    GLCD.CursorToXY(50,15);
    GLCD.print("sec");
    GLCD.CursorToXY(12,25);
    GLCD.print(MAX6675_read_temp(1));
    GLCD.CursorToXY(50,25);
    GLCD.print("°C/sec");
    GLCD.CursorToXY(12,35);
    GLCD.print("Cooling");   
    delay(200);
      
    /* regulation de la temperature tous les 200ms (-3°c max/s) */
    while (time_current == seconde())
    { 
        if (MAX6675_read_temp(5) < (temp_current - (cooling_deg_max)))
        {  
            Relay_on();      
        }
        else 
        { 
            Relay_off(); 
        }
        
        delay(200);
    }      
  } 
  
  /* Reflow finished */
  GLCD.ClearScreen();
  GLCD.CursorToXY(12,35);
  GLCD.print("Reflow finished !");  
  
  delay(6000);
} 

