#include <FastLED.h>
#include "constants.h"
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

