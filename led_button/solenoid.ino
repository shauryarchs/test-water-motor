// Solenoid valve driven through a relay module.

bool solenoidOn = false;

void solenoidWrite(bool on) {
  digitalWrite(RELAY_PIN, on ? RELAY_ACTIVE_LEVEL : !RELAY_ACTIVE_LEVEL);
}

void solenoidSetup() {
  // Set the off level before enabling the output so the relay doesn't click on at boot.
  solenoidWrite(false);
  pinMode(RELAY_PIN, OUTPUT);
}

void solenoidToggle() {
  solenoidOn = !solenoidOn;
  solenoidWrite(solenoidOn);
}
