#include <FastLED.h>
#include "constants.h"
void setup() {
  Serial.begin(9600);
  initSwitches();
  initLEDs();
}

void loop() {
  readSwitches();
  updateLEDs();
}

