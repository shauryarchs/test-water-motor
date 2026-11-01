// LED and solenoid valve toggle with push button for Arduino Uno.
// Each press of the button on D7 toggles the LED on D8 and the
// solenoid valve, which is switched by a relay on D12.

const uint8_t LED_PIN = 8;
const uint8_t BUTTON_PIN = 7;
const uint8_t RELAY_PIN = 12;

// Button wired with an external pull-down resistor: pressed reads HIGH.
// For a button wired to GND instead, use INPUT_PULLUP and LOW.
const uint8_t BUTTON_PIN_MODE = INPUT;
const uint8_t BUTTON_PRESSED_LEVEL = HIGH;

// Level on RELAY_PIN that energizes the relay. Many relay modules are
// active-LOW (IN pulled low turns the relay on). If the solenoid is on
// when the LED is off, change this to HIGH.
const uint8_t RELAY_ACTIVE_LEVEL = LOW;

const unsigned long DEBOUNCE_MS = 50;

void setup() {
  ledSetup();
  solenoidSetup();
  buttonSetup();
}

void loop() {
  if (buttonWasPressed()) {
    ledToggle();
    solenoidToggle();
  }
}
