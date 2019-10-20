#include <Arduino.h>
#include <FastLED.h>
#include "constants.h"

#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

#define MAX_LEDS 75
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
  LEDPair nose = LEDPair(NOSE_LED_COUNT, L_NOSE_LED_PIN, R_NOSE_LED_PIN);
  LEDPair wings = LEDPair(WING_LED_COUNT, L_WING_LED_PIN, R_WING_LED_PIN);
  LEDStrip tail = LEDStrip(TAIL_LED_PIN, 50);
  void init() {
    FastLED.addLeds<LED_TYPE, L_NOSE_LED_PIN, COLOR_ORDER>(nose.left.leds, nose.left.numLEDs).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, R_NOSE_LED_PIN, COLOR_ORDER>(nose.right.leds, nose.right.numLEDs).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, L_WING_LED_PIN, COLOR_ORDER>(wings.left.leds, wings.left.numLEDs).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, R_WING_LED_PIN, COLOR_ORDER>(wings.right.leds, wings.right.numLEDs).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, TAIL_LED_PIN, COLOR_ORDER>(tail.leds, tail.numLEDs).setCorrection(TypicalLEDStrip);
  }
};

AirplaneLEDs airplane = AirplaneLEDs();

void initLEDs() {
    delay( 3000 ); // power-up safety delay
    airplane.init();
}

void updateLEDs() {

}
