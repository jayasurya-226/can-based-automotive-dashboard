/* 
 * File:   message_handler.h
 * Author: banga
 *
 * 
 */

#ifndef MESSAGE_HANDLER_H
#define	MESSAGE_HANDLER_H

#include <stdint.h>   // Standard integer types (uint8_t, uint16_t, etc.)

// LED state definitions
#define LED_OFF 0
#define LED_ON  1

// Right indicator ON (set RB6 & RB7 bits)
#define RIGHT_IND_ON()  (PORTB = PORTB | 0xC0)

// Right indicator OFF (clear RB6 & RB7 bits)
#define RIGHT_IND_OFF() (PORTB = PORTB & ~0xC0)

// Left indicator ON (set RB0 & RB1 bits)
#define LEFT_IND_ON()   (PORTB = PORTB | 0x03)

// Left indicator OFF (clear RB0 & RB1 bits)
#define LEFT_IND_OFF()  (PORTB = PORTB & ~0x03)

// External variables shared across files
extern volatile unsigned char led_state, status;

// Indicator status enumeration

typedef enum {
    e_ind_off, // Indicators OFF
    e_ind_left, // Left indicator ON
    e_ind_right, // Right indicator ON
    e_ind_hazard // Hazard mode (both ON)
} IndicatorStatus;

// Function prototypes
void display_labels(void); // Display static labels on LCD
void process_canbus_data(void); // Process received CAN messages
void handle_speed_data(uint8_t *data, uint8_t len); // Handle speed data
void handle_gear_data(uint8_t *data, uint8_t len); // Handle gear data
void handle_rpm_data(uint8_t *data, uint8_t len); // Handle RPM data
void handle_engine_temp_data(uint8_t *data, uint8_t len); // Handle engine temperature
void handle_indicator_data(uint8_t *data, uint8_t len); // Handle indicator data

#endif	/* MESSAGE_HANDLER_H */