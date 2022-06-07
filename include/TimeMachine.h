#ifndef QLTIMEMACHINE_TIMEMACHINE_H
#define QLTIMEMACHINE_TIMEMACHINE_H

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define BRIGHTNESS 15

class TimeMachine {

    private:
    MD_Parola   *display;

    public:
    TimeMachine(MD_Parola *display);

    void fade(int no_of_loops, int speed_ms);
    void count_down(int from);
    void to_year(int year);
    void setup();
};

#endif //QLTIMEMACHINE_TIMEMACHINE_H
