#include "TimeMachine.h"


TimeMachine::TimeMachine(MD_Parola *display) {
    this->display = display;
}

void TimeMachine::setup() {
    display->begin();
    display->setIntensity(BRIGHTNESS);
    display->displayClear();
}

void TimeMachine::fade(int no_of_loops, int speed_ms) {
  for (int i = 1; i <= no_of_loops; i++) {
    for (int i = 15; i >= 0; i--) {
      delay(speed_ms);
      display->setIntensity(i);
    }
    
    for (int i = 0; i <= 15; i++) {
      delay(speed_ms);
      display->setIntensity(i);
    }
    display->setIntensity(BRIGHTNESS);
  }
}

void TimeMachine::count_down(int from) {
  display->setTextAlignment(PA_RIGHT);
  for (int i = from; i >= 0; i--) {
    display->printf("%2d s", i);
    delay(1000);
  }
}

void TimeMachine::to_year(int year) {
    display->setTextAlignment(PA_CENTER);
    display->print("YEAR");
    fade(5, 50);
    display->printf("%d", year);
    fade(10, 50);
}
