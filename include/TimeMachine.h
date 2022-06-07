#ifndef QLTIMEMACHINE_TIMEMACHINE_H
#define QLTIMEMACHINE_TIMEMACHINE_H

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "DisplayCountdown.h"

#define BRIGHTNESS 15

enum TimeMachineState {
    OFF,
    COUNT_DOWN,
    YEAR_FLASHING
};


class TimeMachine {

    private:
        MD_Parola   *display;
        TimeMachineState state;
        DisplayCountdown displayCountdown;
        int year;

    public:
        TimeMachine(MD_Parola *display);

        void run(int year);
        void stop();
        void tick();
};

#endif //QLTIMEMACHINE_TIMEMACHINE_H
