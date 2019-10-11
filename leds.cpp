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

LEDStrip tail = LEDStrip(TAIL_LED_PIN, 50);
void initLEDs() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, TAIL_LED_PIN, COLOR_ORDER>(tail.leds, tail.numLEDs).setCorrection(TypicalLEDStrip);
}

void updateLEDs() {

}
