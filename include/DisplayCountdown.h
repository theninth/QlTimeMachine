#ifndef QLTIMEMACHINE_DISPLAYCOUNTDOWN_H
#define QLTIMEMACHINE_DISPLAYCOUNTDOWN_H

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

/**
 * Runs a count down on the display.
 */
class DisplayCountdown {

    private:
        MD_Parola       *display;  /** Pointer to display object. */
        unsigned long   last_decrement;  /** When last decrement was done. */
        int             current_no;  /** Current number to display */

    public:
        void set_display(MD_Parola *display);
        void run(int start_no);
        bool tick();
};

#endif  //QLTIMEMACHINE_DISPLAYCOUNTDOWN_H