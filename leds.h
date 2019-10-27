#define FASTLED_RGBW
#include <FastLED.h>
#include "constants.h"
struct LEDStrip {
  const uint8_t pinNo;
  const uint8_t numLEDs;
  CRGB leds[MAX_LEDS];
  LEDStrip(uint8_t pinNo, uint8_t numLEDs) : pinNo(pinNo), numLEDs(numLEDs) { }
};

struct LEDPair {
  LEDStrip left;
  LEDStrip right;
  LEDPair(uint8_t numLEDs, uint8_t leftPin, uint8_t rightPin): left(LEDStrip(leftPin, numLEDs)), right(LEDStrip(rightPin, numLEDs)) {}
};

struct AirplaneLEDs {
  void init();
  void clearLEDs();
  LEDPair nose = LEDPair(NOSE_LED_COUNT, L_NOSE_LED_PIN, R_NOSE_LED_PIN);
  LEDPair wings = LEDPair(WING_LED_COUNT, L_WING_LED_PIN, R_WING_LED_PIN);
  LEDStrip tail = LEDStrip(TAIL_LED_PIN, 50);
};

