    #include "DisplayCountdown.h"
    
    void DisplayCountdown::set_display(MD_Parola *display) {
        this->display = display;
    }

    void DisplayCountdown::run(int start_no) {
        last_decrement = millis();
        current_no = start_no;
    }

    bool DisplayCountdown::tick() {
        if ((millis() - last_decrement) >= 1000) {
            last_decrement = millis();
            current_no--;

            display->setTextAlignment(PA_RIGHT);
            display->printf("%2d s", current_no);

            return (current_no == 0); // If 0, returns true
        }
        return false;
    }