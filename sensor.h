/* 
 * 
 */
#ifndef ECU1_SENSOR_H
#define	ECU1_SENSOR_H

#include <stdint.h>           // Standard integer data types
#include "digital_keypad.h"  // Digital keypad definitions
#include <xc.h>              // PIC microcontroller definitions

#define MAX_GEAR 6            // Maximum gear limit
#define SPEED_ADC_CHANNEL 0x04  // ADC channel used for speed input

#define GEAR_UP     SWITCH1   // Switch used to increase gear
#define GEAR_DOWN   SWITCH2   // Switch used to decrease gear
#define COLLISION   SWITCH3   // Switch used to trigger collision mode

// Function to get speed based on gear position
uint16_t get_speed(unsigned char gear_pos);

// Function to get current gear position
unsigned char get_gear_pos(void);

#endif	/* ECU1_SENSOR_H */
