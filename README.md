# QlTimeMachine

QlTimeMachine is one of my very first projects in C++ (please, be kind).
It is supposed to used on a Wemos D1 Mini (or other microcontroller) with 
the LED-matrix MAX7219 8x32 and a few buttons.

[YouTube video](https://www.youtube.com/watch?v=BGiZFRRJ4Ec)

## Connecting cables

Microcontroller GND -> LED-matrix GND

Microcontroller 5V  -> LED-matrix VCC

Microcontroller D5  -> LED-matrix CLK

Microcontroller D7  -> LED-matrix DIN

Microcontroller D8  -> LED-matrix CS

Microcontroller D1  -> Pushbutton (other pin to GND)

Microcontroller D3  -> Switch (other pin to GND)


## Installation

See instructions on [platformio](https://platformio.org/install).

## Contributing
Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
