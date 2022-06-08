#include "TimeMachine.h"


TimeMachine::TimeMachine(MD_Parola *display) {
    this->display = display;  /** Pointer to display object. */
    this->display->setIntensity(BRIGHTNESS);
    this->display->displayClear();
    this->state = OFF;
    displayCountdown.set_display(display);
    displayPulsatingText.set_display(display);
}

/**
 * Set machine in start mode (to actually run the machine,
 * the tick()-method should be called every n millisecond.)
 */
void TimeMachine::run(int year) {
    this->state = COUNT_DOWN;
    this->year = year;
    displayCountdown.run(10);
}

/**
 * Set machine in stop mode.
 */
void TimeMachine::stop() {
    this->state = OFF;
    this->display->displayClear();
}

/**
 * Move the state of the machine forward (if it should by this tick).
 */
void TimeMachine::tick() {
    if (this->state == OFF) {
        return;
    }
    else if (this->state == COUNT_DOWN) {
        bool is_done = displayCountdown.tick();
        if (is_done) {
            this->state = YEAR_TEXT_FLASHING;
            this->displayPulsatingText.run("YEAR");
        }
    }
    else if (this->state == YEAR_TEXT_FLASHING) {
            bool is_done = displayPulsatingText.tick();
            if (is_done) {
                this->state = YEAR_NO_FLASHING;
                this->displayPulsatingText.run("2022");
            }
    }
    else if (this->state == YEAR_NO_FLASHING) {
            bool is_done = displayPulsatingText.tick();
            if (is_done) {
                this->state = OFF;
                this->display->displayClear();
            }
    }
}