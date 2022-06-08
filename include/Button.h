#ifndef QLTIMEMACHINE_BUTTON_H
#define QLTIMEMACHINE_BUTTON_H

#include <cstdint>

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
        bool _state;
        uint8_t _pin;
};

#endif