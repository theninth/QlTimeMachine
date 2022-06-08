#ifndef QLTIMEMACHINE_BUTTON_H
#define QLTIMEMACHINE_BUTTON_H

#include <cstdint>

/* Time (ms) since last event to not recongnise a new event */
#define QLTIMEMACHINE_BUTTON_DEBOUNCING 500

/**
 * Simple code to check when a button i released.
 * 
 * Source: https://arduino.stackexchange.com/a/48244
 */
class Button
{
    public:
        Button(uint8_t pin) : _pin(pin) {}
        void begin();
        bool isReleased();

    private:
        unsigned long _last_event;
        bool _state;
        uint8_t _pin;
};

#endif