#include "leds.h"

void AirplaneLEDs::init() {
  FastLED.addLeds<LED_TYPE, L_NOSE_LED_PIN, COLOR_ORDER>(nose.left.leds, nose.left.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, R_NOSE_LED_PIN, COLOR_ORDER>(nose.right.leds, nose.right.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, L_WING_LED_PIN, COLOR_ORDER>(wings.left.leds, wings.left.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, R_WING_LED_PIN, COLOR_ORDER>(wings.right.leds, wings.right.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, TAIL_LED_PIN, COLOR_ORDER>(tail.leds, tail.numLEDs).setCorrection(TypicalLEDStrip);
}

