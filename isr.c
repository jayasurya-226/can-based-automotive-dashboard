

#include <xc.h>

// Global timer counter variable (updated in ISR)
extern unsigned long int timer_count;

// Interrupt Service Routine

void __interrupt() isr(void) {
    // Check if Timer0 overflow interrupt occurred
    if (TMR0IF) {
        TMR0 = TMR0 + 9; // Reload Timer0 value for consistent timing

        if (timer_count++ == 20000) // Increment timer count and check limit
        {
            timer_count = 0; // Reset timer count after reaching limit
        }

        TMR0IF = 0; // Clear Timer0 interrupt flag
    }
}