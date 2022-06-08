#ifndef QLTIMEMACHINE_TOGGLESWITCH_H
#define QLTIMEMACHINE_TOGGLESWITCH_H

#include <Arduino.h>
#include <cstdint>

class ToggleSwitch
{
    public:
        ToggleSwitch(uint8_t pin) : _pin(pin) {}
        void begin();
        bool is_enabled();

    private:
        uint8_t _pin;
};

#endif