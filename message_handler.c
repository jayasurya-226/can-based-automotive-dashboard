//HEADER FILES 
#include <xc.h>
#include <string.h>
#include "message_handler.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"

// Timer updated in Timer ISR
extern unsigned long int timer_count;

// Gear display mapping (index = gear value)
static const char gear_str[8][3] ={
    "GN", // 0 - Neutral
    "G1", // 1
    "G2", // 2
    "G3", // 3
    "G4", // 4
    "G5", // 5
    "GR", // 6 - Reverse
    "C_" // 7 - Collision
};

// Display fixed labels on LCD

void display_labels(void) {
    clcd_print("SPD", LINE1(0)); // Speed label
    clcd_print("GER", LINE1(4)); // Gear label
    clcd_print("RPM", LINE1(8)); // RPM label
    clcd_print("IND", LINE1(13)); // Indicator label
}

// ---------- SPEED HANDLER ----------

void handle_speed_data(uint8_t *data, uint8_t len) {
    uint8_t speed = data[0]; // Read speed value

    if (speed > 100) // Limit speed to 100
        speed = 100;

    // Display hundreds place
    if (speed >= 100)
        clcd_putch((speed / 100) + '0', LINE2(0));
    else
        clcd_putch(' ', LINE2(0)); // Blank if not needed

    // Display tens place
    clcd_putch(((speed / 10) % 10) + '0', LINE2(1));

    // Display ones place
    clcd_putch((speed % 10) + '0', LINE2(2));
}

// ---------- GEAR HANDLER ----------

void handle_gear_data(uint8_t *data, uint8_t len) {
    uint8_t gear = data[0]; // Read gear value

    if (gear <= 7) // Valid gear range check
    {
        clcd_print(gear_str[gear], LINE2(4)); // Display gear
    }
}

// ---------- RPM HANDLER ----------

void handle_rpm_data(uint8_t *data, uint8_t len) {
    uint16_t rpm;

    // Combine two bytes to form 16-bit RPM value
    rpm = ((uint16_t) data[0] << 8) | data[1];

    // Display RPM digits
    clcd_putch((rpm / 1000) + '0', LINE2(8));
    clcd_putch((rpm / 100) % 10 + '0', LINE2(9));
    clcd_putch((rpm / 10) % 10 + '0', LINE2(10));
    clcd_putch((rpm % 10) + '0', LINE2(11));
}

// ---------- INDICATOR HANDLER ----------

void handle_indicator_data(uint8_t *data, uint8_t len) {
    uint8_t indicator = data[0]; // Read indicator value

    if (timer_count <= 10000) // Blinking time window
    {
        if (indicator == e_ind_off) {
            LEFT_IND_OFF(); // Turn OFF left indicator
            RIGHT_IND_OFF(); // Turn OFF right indicator
            clcd_putch(' ', LINE2(14));
            clcd_putch(' ', LINE2(15));
        } else if (indicator == e_ind_left) {
            LEFT_IND_ON(); // Turn ON left indicator
            RIGHT_IND_OFF();
            clcd_putch('<', LINE2(14));
            clcd_putch(' ', LINE2(15));
        } else if (indicator == e_ind_right) {
            LEFT_IND_OFF();
            RIGHT_IND_ON(); // Turn ON right indicator
            clcd_putch(' ', LINE2(14));
            clcd_putch('>', LINE2(15));
        } else if (indicator == e_ind_hazard) {
            LEFT_IND_ON(); // Turn ON both indicators
            RIGHT_IND_ON();
            clcd_putch('<', LINE2(14));
            clcd_putch('>', LINE2(15));
        }
    } else {
        LEFT_IND_OFF(); // Turn OFF indicators after timeout
        RIGHT_IND_OFF();
        clcd_putch(' ', LINE2(14));
        clcd_putch(' ', LINE2(15));
    }
}

// ---------- CAN PROCESS FUNCTION ----------

void process_canbus_data(void) {
    uint8_t data[8]; // CAN data buffer
    uint8_t len; // Data length
    uint16_t msg_id; // Message ID
    static uint8_t collision_flag = 0; // Collision state flag

    // Receive CAN message
    if (!can_receive(&msg_id, data, &len))
        return; // Exit if no new message

    if (!collision_flag) // Normal mode
    {
        if (msg_id == SPEED_MSG_ID) {
            handle_speed_data(data, len); // Process speed
        } else if (msg_id == GEAR_MSG_ID) {
            handle_gear_data(data, len); // Process gear

            if (data[0] == 7) // Collision detected
            {
                collision_flag = 1; // Set collision flag
                clcd_clear(); // Clear LCD
                clcd_print("_C !", LINE1(0)); // Show collision message
            }
        } else if (msg_id == RPM_MSG_ID) {
            handle_rpm_data(data, len); // Process RPM
        } else if (msg_id == INDICATOR_MSG_ID) {
            handle_indicator_data(data, len); // Process indicator
        }
    } else // Collision mode
    {
        if (msg_id == GEAR_MSG_ID && data[0] != 7) {
            collision_flag = 0; // Exit collision mode
            clcd_clear(); // Clear LCD
            display_labels(); // Restore normal labels
        }
    }
}