#include "color.h"
#include <FastLED.h>
#include "constants.h"

#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

#define MAX_LEDS 75
struct LEDStrip {
  uint8_t numLEDs;
  CRGB leds[MAX_LEDS];
};

LEDStrip l_nose;
LEDStrip r_nose;
LEDStrip l_wing;
LEDStrip r_wing;
LEDStrip tail;
void initLEDs() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, TAIL_LED_PIN, COLOR_ORDER>(tail.leds, tail.numLEDs).setCorrection(TypicalLEDStrip);
}

void updateLEDs() {

}
