#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "TimeMachine.h"
#include "Button.h"
#include "ToggleSwitch.h"

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 15

MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
TimeMachine timeMachine(&Display);

Button runButton(5);        // GPIO5 = D1 (on D1 Mini).
ToggleSwitch timeToggle(4); // GPIO4 = D2 (on D1 Mini).


void setup() {
    Serial.begin(115200);
    Display.begin();
    runButton.begin();
    timeToggle.begin();
}

void loop() {
    timeMachine.tick();
    if (runButton.isReleased()) {
        if (!timeMachine.is_running()) {
            Serial.printf("Läge: %d", timeToggle.is_enabled());
            timeMachine.run(timeToggle.is_enabled() ? 2022 : 1222);
        } else {
            timeMachine.stop();
        }
    }
}
