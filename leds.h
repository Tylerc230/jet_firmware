#ifndef INCLUDE_JET_LEDS
#define INCLUDE_JET_LEDS
#include <FastLED.h>
#include "constants.h"
struct LEDStrip {
  void setLED(int index, CRGB color);
  void fill(CRGB color);
  LEDStrip(uint8_t pinNo, uint8_t numLEDs) : pinNo(pinNo), numLEDs(numLEDs) { }
  const uint8_t pinNo;
  const uint8_t numLEDs;
  CRGB leds[MAX_LEDS];
};

struct LEDPair {
  void setPair(int index, CRGB color);
  void fill(CRGB color);
  LEDStrip left;
  LEDStrip right;
  LEDPair(uint8_t numLEDs, uint8_t leftPin, uint8_t rightPin): left(LEDStrip(leftPin, numLEDs)), right(LEDStrip(rightPin, numLEDs)) {}
};

struct AirplaneLEDs {
  void init();
  void fill(CRGB color);
  void clearLEDs();
  void setAll(int index, CRGB color);
  LEDPair nose = LEDPair(NOSE_LED_COUNT, L_NOSE_LED_PIN, R_NOSE_LED_PIN);
  LEDPair wings = LEDPair(WING_LED_COUNT, L_WING_LED_PIN, R_WING_LED_PIN);
  LEDStrip tail = LEDStrip(TAIL_LED_PIN, TAIL_LED_COUNT);
};

#endif
