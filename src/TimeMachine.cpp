#include <stdio.h>
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
 * the update()-method should be called every n millisecond.)
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

bool TimeMachine::is_running() {
    return this->state != OFF;
}

/**
 * Move the state of the machine forward (if it should by this update).
 */
void TimeMachine::update() {
    char yearText[10];

    if (this->state == OFF) {
        return;
    }
    else if (this->state == COUNT_DOWN) {
        bool is_done = displayCountdown.update();
        if (is_done) {
            this->state = YEAR_TEXT_FLASHING;
            this->displayPulsatingText.run("YEAR");
        }
    }
    else if (this->state == YEAR_TEXT_FLASHING) {
        bool is_done = displayPulsatingText.update();
        if (is_done) {
            this->state = YEAR_NO_FLASHING;
            this->displayPulsatingText.run(yearText);
        }
    }
    else if (this->state == YEAR_NO_FLASHING) {
        bool is_done = displayPulsatingText.update();
        if (is_done) {
            this->state = OFF;
            this->display->displayClear();
        }
    }
}
