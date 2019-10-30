#include "leds.h"
#include "colorutils.h"
void LEDStrip::setLED(int index, CRGB color) {
  if (index >= numLEDs) {
    return;
  }
  leds[index] = color;
}


void LEDStrip::fill(CRGB color) {
  fill_solid(&(leds[0]), numLEDs, color);
}

void LEDPair::setPair(int index, CRGB color) {
  left.setLED(index, color);
  right.setLED(index, color);
}

void LEDPair::fill(CRGB color) {
  left.fill(color);
  right.fill(color);
}

void AirplaneLEDs::init() {
  FastLED.addLeds<LED_TYPE, L_NOSE_LED_PIN, COLOR_ORDER>(nose.left.leds, nose.left.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, R_NOSE_LED_PIN, COLOR_ORDER>(nose.right.leds, nose.right.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, L_WING_LED_PIN, COLOR_ORDER>(wings.left.leds, wings.left.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, R_WING_LED_PIN, COLOR_ORDER>(wings.right.leds, wings.right.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, TAIL_LED_PIN, COLOR_ORDER>(tail.leds, tail.numLEDs).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(  BRIGHTNESS );
}

void AirplaneLEDs::setAll(int index, CRGB color) {
  nose.setPair(index, color);
  wings.setPair(index, color);
  tail.setLED(index, color);
}


void AirplaneLEDs::fill(CRGB color) {
  nose.fill(color);
  wings.fill(color);
  tail.fill(color);
}

void AirplaneLEDs::clearLEDs() {
  fill(CRGB::Black);
}
