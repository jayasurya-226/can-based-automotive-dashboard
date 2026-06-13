
#include "sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "digital_keypad.h"

uint16_t get_speed(unsigned char gear_pos) {
    uint16_t adc_val; // Variable to store ADC value
    uint16_t speed; // Variable to store calculated speed

    adc_val = read_adc(SPEED_ADC_CHANNEL); // Read ADC value (0?1023)

    speed = adc_val / 10.23; // Map ADC value to speed range (0?100)

    if (gear_pos == 7) // If collision gear is active
        speed /= 5; // Reduce speed

    // Clamp speed to maximum of 100
    if (speed > 100)
        speed = 100;

    return speed; // Return final speed
}

unsigned char get_gear_pos(void) {
    static unsigned char gear = 0; // Store gear position (start with GN)
    unsigned char key; // Variable to store key input

    key = read_digital_keypad(STATE_CHANGE); // Read keypad state

    if (key != ALL_RELEASED) // If any key is pressed
    {
        // If collision mode and any key is pressed ? go to GN
        if (gear == 7 && (key == SWITCH1 || key == SWITCH2)) {
            gear = 0; // Reset gear to GN
        } else {
            if (key == SWITCH1) // Gear up button
            {
                if (gear < 6) // Maximum gear is G6
                    gear++; // Increment gear
            } else if (key == SWITCH2) // Gear down button
            {
                if (gear > 0) // Minimum gear is GN
                    gear--; // Decrement gear
            } else if (key == SWITCH3) // Collision button
            {
                gear = 7; // Set gear to collision mode
            }
        }
    }

    return gear; // Return current gear position
}