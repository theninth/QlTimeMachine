#include "DisplayCountdown.h"
    
/**
* Sets pointer to display object to use.
*/
void DisplayCountdown::set_display(MD_Parola *display) {
    this->display = display;
}

/**
 * Set module in run mode (to actually run, the update()-method
 * has to be called every n milliseconds.)
 */
void DisplayCountdown::run(int start_no) {
    last_decrement = millis();
    current_no = start_no;
    display->setTextAlignment(PA_RIGHT);
    display->printf("%2d s", start_no);
}

/**
 * Move the state of the module forward (if it should by this update).
 */
 bool DisplayCountdown::update() {
    if ((millis() - last_decrement) >= 1000) {
        last_decrement = millis();
        current_no--;

        display->printf("%2d s", current_no);

        return (current_no == 0); // If count down finished, return true
    }
    return false;
}