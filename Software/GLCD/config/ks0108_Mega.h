/*
 * ks0108_Mega.h - User specific configuration for Arduino GLCD library
 *
 * Use this file to set io pins
 *
 * The configuration below uses a single port for data 
 * and has the same wiring as the mega config from the previous ks0108 library 
 *
*/

#ifndef GLCD_PIN_CONFIG_H
#define GLCD_PIN_CONFIG_H

/*
 * define name for pin configuration
 */
#define glcd_PinConfigName "ks0108-Mega"

/*********************************************************/
/*  Configuration for assigning LCD bits to Arduino Pins */
/*********************************************************/
/*
 * Pins used for Commands
 */
#define glcdCSEL1     26    // CS1 Bit  
#define glcdCSEL2     27    // CS2 Bit
#define glcdRW        29    // R/W Bit
#define glcdDI        28    // D/I Bit 
#define glcdEN        25    // EN Bit

#if NBR_CHIP_SELECT_PINS > 2
#define glcdCSEL3     32   // third chip select if needed
#endif

#if NBR_CHIP_SELECT_PINS > 3
#define glcdCSEL4     31   // fourth chip select if needed
#endif

/*
 * Data pin definitions
 * This version uses pins 22-29 for LCD Data 
 */
#define glcdData0Pin    30
#define glcdData1Pin    31
#define glcdData2Pin    32
#define glcdData3Pin    33
#define glcdData4Pin    34
#define glcdData5Pin    35
#define glcdData6Pin    36
#define glcdData7Pin    37

// Reset Bit  - uncomment the next line if reset is connected to an output pin
//#define glcdRES         30    // Reset Bit

#endif //GLCD_PIN_CONFIG_H
