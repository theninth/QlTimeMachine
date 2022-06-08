#include "ToggleSwitch.h"

void ToggleSwitch::begin() {
    pinMode(_pin, INPUT_PULLUP);
}

bool ToggleSwitch::is_enabled() {
    return digitalRead(_pin) == 0 ? true : false;
}