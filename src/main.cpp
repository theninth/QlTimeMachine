#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "TimeMachine.h"

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 15

MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
TimeMachine timeMachine(&Display);

void setup() {
    timeMachine.setup();
}

void loop() {
    timeMachine.count_down(10);
    timeMachine.to_year(1222);
    Display.displayClear();
    delay(10000);
}
