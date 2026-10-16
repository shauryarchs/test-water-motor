// LED toggle with push button for Arduino Uno.
// Each press of the button on D7 toggles the LED on D8.

const uint8_t LED_PIN = 8;
const uint8_t BUTTON_PIN = 7;

// Button wired with an external pull-down resistor: pressed reads HIGH.
// For a button wired to GND instead, use INPUT_PULLUP and LOW.
const uint8_t BUTTON_PIN_MODE = INPUT;
const uint8_t BUTTON_PRESSED_LEVEL = HIGH;

const unsigned long DEBOUNCE_MS = 50;

void setup() {
  ledSetup();
  buttonSetup();
}

void loop() {
  if (buttonWasPressed()) {
    ledToggle();
  }
}
