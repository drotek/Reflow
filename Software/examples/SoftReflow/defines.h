/*******************************************
*                 DIVERS
*******************************************/
#define VERSION   1 // Version of firmware
#define seconde() (millis()/1000)


/*******************************************
*                 IO
*******************************************/
#define RIGHT    21
#define DOWN     18
#define UP        2
#define OK       20
#define LEFT     19
#define VERSION   1
#define BUZZER   42
#define FAN       5
#define RELAY    43


/*******************************************
*             DEFAULT VALUES
*******************************************/

#define PREHEAT_TEMP      120
#define PREHEAT_TEMP_MAX    3  
#define SOAK_TEMP         180
#define SOAK_TIME         120
#define REFLOW_TEMP       220
#define REFLOW_TIME         5
#define COOLING_TEMP       50
#define COOLING_TEMP_MAX    3


/*******************************************
*             EEPROM
*******************************************/
#define BOOT_ADDR           1
#define BOOT_VALUE         31

#define SOAK_TEMP_MSB_ADDR  5
#define SOAK_TEMP_LSB_ADDR  6

#define SOAK_TIME_MSB_ADDR  7
#define SOAK_TIME_LSB_ADDR  8

#define PREHEAT_TEMP_MSB_ADDR  9
#define PREHEAT_TEMP_LSB_ADDR  10

#define PREHEAT_DEG_MAX_MSB_ADDR  11
#define PREHEAT_DEG_MAX_LSB_ADDR  12

#define REFLOW_TEMP_MSB_ADDR  13
#define REFLOW_TEMP_LSB_ADDR  14

#define REFLOW_TIME_MSB_ADDR  15
#define REFLOW_TIME_LSB_ADDR  16

#define COOLING_TEMP_MSB_ADDR  17
#define COOLING_TEMP_LSB_ADDR  18

#define COOLING_DEG_MAX_MSB_ADDR  19
#define COOLING_DEG_MAX_LSB_ADDR  20


/*******************************************
*                 MAX6675
*******************************************/
#define UNIT      1    // Units to readout temp (0= °F, 1= °C)
#define OFFSET  0.0    // Temperature compensation error



