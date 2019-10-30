#include "ColorProgram.h"
#include "../leds.h"
#include "../inputs.h"
#include "colorpalettes.h"
#include "colorutils.h"

void ColorProgram::init(Inputs & inputs, AirplaneLEDs & airplane) {
  inputs.progMod.max = NUM_PALETTES;
  airplane.clearLEDs();
}

void ColorProgram::update(Inputs & inputs, AirplaneLEDs & airplane) {
  Serial.print(inputs.s1.state);Serial.print(" ");
  Serial.print(inputs.s2.state);Serial.print(" ");
  Serial.print(inputs.horn.state);Serial.print(" ");
  Serial.print(inputs.progSelect.pos);Serial.print(" ");
  Serial.print(inputs.progMod.pos);Serial.print(" ");
  Serial.println();

  CRGBPalette16 palettes [NUM_PALETTES] = {RainbowColors_p, LavaColors_p, OceanColors_p, CloudColors_p, ForestColors_p, HeatColors_p, PartyColors_p};
  CRGBPalette16 currentPalette = palettes[inputs.progMod.pos];
  for( int i = 0; i < MAX_LEDS; i++) {
    CRGB color = ColorFromPalette( currentPalette, index + i, 255, LINEARBLEND);
    airplane.setAll(i, color);
  }
  index ++;
}
