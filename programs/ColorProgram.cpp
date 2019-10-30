#include "ColorProgram.h"
#include "../leds.h"
#include "../inputs.h"

void ColorProgram::init(Inputs & inputs, AirplaneLEDs & airplane) {
  airplane.clearLEDs();
}

void ColorProgram::update(Inputs & inputs, AirplaneLEDs & airplane) {
  Serial.print(inputs.s1.state);Serial.print(" ");
  Serial.print(inputs.s2.state);Serial.print(" ");
  Serial.print(inputs.horn.state);Serial.print(" ");
  Serial.print(inputs.progSelect.pos);Serial.print(" ");
  Serial.print(inputs.progMod.pos);Serial.print(" ");
  Serial.println();
  int i =  index++ % MAX_LEDS;
  airplane.setAll(i, CRGB::Pink);
  if (i == 0) {
    airplane.clearLEDs();
  }
}


