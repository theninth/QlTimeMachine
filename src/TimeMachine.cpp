#include "TimeMachine.h"


TimeMachine::TimeMachine(MD_Parola *display) {
    this->display = display;
    this->display->setIntensity(BRIGHTNESS);
    this->display->displayClear();
    this->state = OFF;
    displayCountdown.set_display(display);
}

void TimeMachine::run(int year) {
    this->state = COUNT_DOWN;
    this->year = year;
    displayCountdown.run(10);
}

void TimeMachine::stop() {
    this->state = OFF;
}

void TimeMachine::tick() {
    if (this->state == OFF) {
        return;
    }
    else if (this->state == COUNT_DOWN) {
        bool is_done = displayCountdown.tick();
        if (is_done) this->state = YEAR_FLASHING;
    }
    else if (this->state == YEAR_FLASHING) {

    }
}