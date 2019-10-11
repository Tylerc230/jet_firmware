#include <Arduino.h>
#include "inputs.h"
#include "leds.h"
void setup() {
  Serial.begin(9600);
  initSwitches();
  initKnobs();
  initLEDs();
}

void loop() {
  readSwitches();
  readKnobs();
  updateLEDs();
}

