#include <Arduino.h>
#include "Button.h"

void Button::begin() {
    pinMode(_pin, INPUT_PULLUP);
    _state = digitalRead(_pin);
    _last_event = millis();
}

bool Button::isReleased() { 
    if ((millis() - _last_event) <= QLTIMEMACHINE_BUTTON_DEBOUNCING) return false;

    bool v = digitalRead(_pin);
    if (v != _state) {
        _state = v;
        if (_state) {
            _last_event = millis();
            return true;
        }
    }
    return false;
}