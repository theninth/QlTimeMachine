#ifndef QLTIMEMACHINE_TIMEMACHINE_H
#define QLTIMEMACHINE_TIMEMACHINE_H

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "DisplayCountdown.h"
#include "DisplayPulsatingText.h"

#define BRIGHTNESS 15

/**
 * Current state of time machine.
 */
enum TimeMachineState {
    OFF,                 /** Time machine is off.                */
    COUNT_DOWN,          /** Time machine is running count down. */
    YEAR_TEXT_FLASHING,  /** Time machine is flashing the text.  */
    YEAR_NO_FLASHING     /** Time machine is flashing the year   */
};


/**
 * Does some cool stuff with text on a display
 * to simulate a time travel machine.
 */
class TimeMachine {

    private:
        MD_Parola   *display;  /** Pointer to display object. */
        TimeMachineState state;  /** Current state of machine */
        DisplayCountdown displayCountdown;  /** DisplayCountdown module */
        DisplayPulsatingText displayPulsatingText; /** DisplayPulsationText module */
        int year;  /** Year to travel to. */

    public:
        TimeMachine(MD_Parola *display);

        void run(int year);
        void stop();
        void tick();
        bool is_running();
};

#endif //QLTIMEMACHINE_TIMEMACHINE_H
