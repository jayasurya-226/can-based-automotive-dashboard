/* 
 * File:   sensor.h
 * Author: banga
 *
 * 
 */
#ifndef ECU1_SENSOR_H
#define	ECU1_SENSOR_H

#include <stdint.h>           // Standard integer data types
#include "digital_keypad.h"  // Digital keypad interface
#include <xc.h>              // PIC microcontroller definitions

#define RPM_ADC_CHANNEL 0x04      // ADC channel for RPM sensor
#define ENG_TEMP_ADC_CHANNEL 0x06 // ADC channel for engine temperature sensor

#define LED_OFF 0                // LED OFF state
#define LED_ON  1                // LED ON state

// Macro to turn ON right indicator LEDs (RB6 & RB7)
#define RIGHT_IND_ON()  (PORTB = PORTB | 0xC0)

// Macro to turn OFF right indicator LEDs (RB6 & RB7)
#define RIGHT_IND_OFF() (PORTB = PORTB & ~0xC0)

// Macro to turn ON left indicator LEDs (RB0 & RB1)
#define LEFT_IND_ON()   (PORTB = PORTB | 0x03)

// Macro to turn OFF left indicator LEDs (RB0 & RB1)
#define LEFT_IND_OFF()  (PORTB = PORTB & ~0x03)

// Enumeration for indicator states

typedef enum {
    e_ind_off, // Indicator OFF
    e_ind_left, // Left indicator ON
    e_ind_right, // Right indicator ON
    e_ind_hazard // Hazard mode (both indicators ON)
} IndicatorStatus;

// External variables to store previous and current indicator status
extern volatile IndicatorStatus prev_ind_status, cur_ind_status;

// External variable to store LED state
extern volatile unsigned char led_state;

// Function to get RPM value from ADC
uint16_t get_rpm(void);

// Function to get engine temperature from ADC
uint16_t get_engine_temp(void);

// Function to process indicator input and return current status
IndicatorStatus process_indicator(void);

#endif	/* ECU1_SENSOR_H */