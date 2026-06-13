/*
 * File:   main.c
 * Author: banga
 *
 */

// HEADER FILES
#include <xc.h>
#include "adc.h"
#include "digital_keypad.h"
#include "sensor.h"
#include "msg_id.h"
#include "can.h"

#define _XTAL_FREQ 20000000   // Set system clock frequency as per your crystal

/* ---------------- Function Prototypes ---------------- */
void init_config(void); // Initialize all peripherals
void rpm_to_bcd(unsigned int rpm, unsigned char *bcd); // Convert RPM to BCD format

/* ---------------- INIT ---------------- */
void init_config(void) {
    init_adc(); // Initialize ADC module
    init_digital_keypad(); // Initialize digital keypad
    init_can(); // Initialize CAN module
}

/* ---------------- RPM ? BCD ---------------- */

/*
   RPM range: 0?6000

   bcd[0] = thousands | hundreds
   bcd[1] = tens | units
 */
void rpm_to_bcd(unsigned int rpm, unsigned char *bcd) {
    unsigned char thousands, hundreds, tens, units; // Variables to store digits

    thousands = (rpm / 1000) % 10; // Extract thousands digit
    hundreds = (rpm / 100) % 10; // Extract hundreds digit
    tens = (rpm / 10) % 10; // Extract tens digit
    units = rpm % 10; // Extract units digit

    bcd[0] = (thousands << 4) | hundreds; // Pack thousands and hundreds into one byte
    bcd[1] = (tens << 4) | units; // Pack tens and units into one byte
}

/* ---------------- MAIN ---------------- */
void main(void) {
    unsigned char indicator; // Variable to store indicator status
    unsigned int rpm; // Variable to store RPM value
    unsigned char data[2]; // BCD needs only 2 bytes

    init_config(); // Initialize system

    while (1) {
        /* Read indicator */
        indicator = process_indicator(); // Get current indicator state
        can_transmit(INDICATOR_MSG_ID, &indicator, 1); // Send indicator data via CAN
        __delay_ms(10); // Small delay

        /* Read RPM and send as BCD */
        rpm = get_rpm(); // Get RPM value (0?6000)
        rpm_to_bcd(rpm, data); // Convert RPM to BCD
        can_transmit(RPM_MSG_ID, data, 2); // Send RPM data via CAN
        __delay_ms(10); // Small delay
    }
}