// Hello World test sketch for Arduino Uno.
// Prints "Hello World" to the serial monitor every second.
// Send any key from the serial monitor to stop printing.

const unsigned long PRINT_INTERVAL_MS = 1000;

unsigned long lastPrintMs = 0;
bool stopped = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Send any key to stop printing.");
}

void loop() {
  if (stopped) {
    return;
  }

  if (Serial.available() > 0) {
    // Drain everything that was sent (key plus any line ending).
    while (Serial.available() > 0) {
      Serial.read();
    }
    stopped = true;
    Serial.println("Stopped. Press reset to start again.");
    return;
  }

  unsigned long now = millis();
  if (now - lastPrintMs >= PRINT_INTERVAL_MS) {
    lastPrintMs = now;
    Serial.println("Hello World");
  }
}
