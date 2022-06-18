#include "DisplayPulsatingText.h"

DisplayPulsatingText::DisplayPulsatingText()
{
    iteration = 1;
}

/**
 * Resets state.
 */
void DisplayPulsatingText::reset() {
    current_brightness = MAX_BRIGHTNESS;
    state = PULSATING_FADING_DOWN;
    iteration = 1;
}

/**
* Sets pointer to display object to use.
*/
void DisplayPulsatingText::set_display(MD_Parola *display) {
    this->display = display;
}

/**
 * Set module in run mode (to actually run, the update()-method
 * has to be called every n milliseconds.)
 */
void DisplayPulsatingText::run(std::string text) {
    last_update = millis();
    reset();
    this->display->displayClear();
    this->display->printf(text.c_str());
}

/**
 * Set module in a stopped mode (the update()-method does nothing.)
 */
void DisplayPulsatingText::stop() {
    reset();
}

/**
 * Steps the brightness one step up or down (depending on state).
 * @return True if iteration is done.
 */
bool DisplayPulsatingText::step() {
    if (current_brightness > 0 && state == PULSATING_FADING_DOWN) {
        this->display->setIntensity(--current_brightness);
    }
    else if (current_brightness < MAX_BRIGHTNESS && state == PULSATING_FADING_UP)
    {
        this->display->setIntensity(++current_brightness);
    }
    else if (current_brightness == 0) {
        state = PULSATING_FADING_UP;
        this->display->setIntensity(++current_brightness);
    }
    else if (current_brightness == MAX_BRIGHTNESS) {
        state = PULSATING_FADING_DOWN;
        return true;
    }
    return false;
}

/**
 * Move the state of the module forward (if it should by this update).
 * @return true if module is done, otherwise false.
 */
 bool DisplayPulsatingText::update() {
    if (state == PULSATING_FADING_OFF) return false;

    if ((millis() - last_update) >= UPDATE_PULSE_INTERVAL) {
        last_update = millis();        
        if (iteration > NO_OF_PULSE_REPEATS) {
            stop();
            return true;
        }
        else if (step()) iteration++;
    }
    return false;
}