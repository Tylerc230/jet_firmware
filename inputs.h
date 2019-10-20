#include <Arduino.h>
#include "constants.h"

struct Switch {
  Switch(uint8_t pin): pin(pin) { }
  void init();
  void read();
  const uint8_t pin;
  uint8_t state = HIGH;
};

struct EncoderKnob {
  EncoderKnob(uint8_t p0, uint8_t p1): pin0(p0), pin1(p1) { }
  const uint8_t pin0;
  const uint8_t pin1;
  uint8_t pin0LastReading = LOW;
  uint8_t pos = 0;
  void init();
  void read();
};

struct Inputs {
  EncoderKnob progSelect = EncoderKnob(KNOB_A_PIN_0, KNOB_A_PIN_1);
  EncoderKnob progMod = EncoderKnob(KNOB_B_PIN_0, KNOB_B_PIN_1);
  Switch horn = Switch(SWITCH_A_PIN);
  Switch s1 = Switch(SWITCH_B_PIN);
  Switch s2 = Switch(SWITCH_C_PIN);
  void init();
  void read();
};

