#ifndef QLTIMEMACHINE_DISPLAYCOUNTDOWN_H
#define QLTIMEMACHINE_DISPLAYCOUNTDOWN_H

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

class DisplayCountdown {

    private:
        MD_Parola       *display;
        unsigned long   last_decrement;
        int             current_no;

    public:
        void set_display(MD_Parola *display);
        void run(int start_no);
        bool tick();
};

#endif  //QLTIMEMACHINE_DISPLAYCOUNTDOWN_H