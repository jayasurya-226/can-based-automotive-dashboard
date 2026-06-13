#include "sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "digital_keypad.h"

uint16_t get_rpm(void) {
    uint16_t adc_val; // Variable to store ADC value
    uint16_t rpm; // Variable to store calculated RPM

    adc_val = read_adc(CHANNEL4); // Read ADC value from channel 4

    rpm = (adc_val / 10.23) * 60; // Convert ADC value to RPM scale

    return rpm; // Return calculated RPM
}

IndicatorStatus process_indicator() {
    // Implement the indicator function
    static int indicator = 0x00; // Variable to store current indicator state
    int key; // Variable to store pressed key

    key = read_digital_keypad(STATE_CHANGE); // Read keypad state

    if (key != ALL_RELEASED) // Check if any key is pressed
    {
        if (key == SWITCH1) // Left indicator switch
            indicator = e_ind_left; // Set left indicator
        else if (key == SWITCH2) // Right indicator switch
            indicator = e_ind_right; // Set right indicator
        else if (key == SWITCH3) // Hazard switch
            indicator = e_ind_hazard; // Set hazard mode
        else if (key == SWITCH4) // OFF switch
            indicator = e_ind_off; // Turn OFF indicators
    }

    return indicator; // Return current indicator status
}