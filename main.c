#include <xc.h>
#include "adc.h"
#include "digital_keypad.h"
#include "can.h"
#include "sensor.h"
#include "msg_id.h"

#define _XTAL_FREQ 20000000   // Define system clock frequency 

/* ---------------- Function Prototypes ---------------- */
void init_config(void); // Function to initialize all peripherals
void speed_to_bcd(unsigned int speed, unsigned char *bcd); // Convert speed to BCD format

/* ---------------- Global Variables ---------------- */
unsigned long int timer_count; // Global timer counter variable

/* ---------------- Init ---------------- */
void init_config(void) {
    init_adc(); // Initialize ADC module
    init_digital_keypad(); // Initialize keypad
    init_can(); // Initialize CAN module
}

/* ---------------- SPEED ? BCD ---------------- */

/*
   Speed range assumed: 0?999
   BCD Format:
   bcd[0] = hundreds | tens
   bcd[1] = units | 0
 */
void speed_to_bcd(unsigned int speed, unsigned char *bcd) {
    unsigned char hundreds, tens, units; // Variables to store digits

    hundreds = (speed / 100) % 10; // Extract hundreds digit
    tens = (speed / 10) % 10; // Extract tens digit
    units = speed % 10; // Extract units digit

    bcd[0] = (hundreds << 4) | tens; // Pack hundreds and tens into one byte
    bcd[1] = (units << 4); // Pack units into high nibble
}

/* ---------------- MAIN ---------------- */
int main(void) {
    init_config(); // Initialize system

    unsigned int speed = 0; // Variable to store speed
    unsigned char gear_pos = 0; // Variable to store gear position
    unsigned char data[2]; // BCD uses only 2 bytes

    while (1) {
        __delay_ms(10); // Small delay

        /* Read Gear Position */
        gear_pos = get_gear_pos(); // Read current gear
        can_transmit(GEAR_MSG_ID, &gear_pos, 1); // Send gear via CAN

        __delay_ms(10); // Small delay

        /* Read Speed and Send as BCD */
        speed = get_speed(gear_pos); // Get speed based on gear
        speed_to_bcd(speed, data); // Convert speed to BCD
        can_transmit(SPEED_MSG_ID, data, 2); // Send speed via CAN
    }
}