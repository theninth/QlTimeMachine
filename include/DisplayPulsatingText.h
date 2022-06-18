#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#ifndef QLTIMEMACHINE_DISPLAYPULSATINGTEXT_H
#define QLTIMEMACHINE_DISPLAYPULSATINGTEXT_H

/* How long to wait before moving to next brightness */
#define UPDATE_PULSE_INTERVAL 100

/* Number of times to repeat */
#define NO_OF_PULSE_REPEATS 2

#define MAX_BRIGHTNESS 15

enum PulsatingTextState {
    PULSATING_FADING_OFF,
    PULSATING_FADING_UP,
    PULSATING_FADING_DOWN
};

class DisplayPulsatingText
{
    private:
        /** Pointer to display object. */
        MD_Parola       *display;

        /** When last update was done. */
        unsigned long   last_update;
    
        /** Current iteration (iterates until NO_OF_PULSE_REPEATS) */
        int             iteration;

        /** Current brightness */
        int             current_brightness;

        /** State of machine */
        PulsatingTextState state;

        bool step();
        void reset();
    public:
        DisplayPulsatingText();
        void set_display(MD_Parola *display);
        void run(std::string text);
        void stop();
        bool update();
};

#endif