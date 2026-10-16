// Debounced push button input.

int buttonStableState;
int buttonLastReading;
unsigned long buttonLastChangeMs = 0;

void buttonSetup() {
  pinMode(BUTTON_PIN, BUTTON_PIN_MODE);
  buttonStableState = digitalRead(BUTTON_PIN);
  buttonLastReading = buttonStableState;
}

// Returns true once per press, after the reading has been stable for DEBOUNCE_MS.
bool buttonWasPressed() {
  int reading = digitalRead(BUTTON_PIN);
  unsigned long now = millis();

  if (reading != buttonLastReading) {
    buttonLastReading = reading;
    buttonLastChangeMs = now;
  }

  if (now - buttonLastChangeMs >= DEBOUNCE_MS && reading != buttonStableState) {
    buttonStableState = reading;
    return buttonStableState == BUTTON_PRESSED_LEVEL;
  }

  return false;
}
