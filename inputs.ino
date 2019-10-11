#include "constants.h"
#define COUNT(array) sizeof(array)/sizeof(array[0])

struct Switch {
  Switch(uint8_t pin): pin(pin) { }
  void init() {
    pinMode(pin, INPUT_PULLUP);
  }
  void read() {
    state = digitalRead(pin);
  }
  const uint8_t pin;
  uint8_t state = HIGH;
};

Switch switches[3] = {
  Switch(SWITCH_A_PIN),
  Switch(SWITCH_B_PIN),
  Switch(SWITCH_C_PIN)
};
const int switchCount = COUNT(switches);

struct EncoderKnob {
  EncoderKnob(uint8_t p0, uint8_t p1): pin0(p0), pin1(p1) { }
  void init() {
    pinMode(pin0, INPUT);
    pinMode(pin1, INPUT);
  }
  void read() {
    int p0 = digitalRead(pin0);
    if (pin0LastReading == LOW && p0 == HIGH) {
      int p1 = digitalRead(pin1);
      if (p1 == LOW) {
        pos--;
      } else {
        pos++;
      }
    }
    pin0LastReading = p0;
  }
  const uint8_t pin0;
  const uint8_t pin1;
  uint8_t pin0LastReading = LOW;
  uint8_t pos = 0;
};

EncoderKnob knobs[2] = {
  EncoderKnob(KNOB_A_PIN_0, KNOB_A_PIN_1),
  EncoderKnob(KNOB_B_PIN_0, KNOB_B_PIN_1)
};
const int knobCount = COUNT(knobs);

void initSwitches() {
  for (int i = 0; i < switchCount; i++) {
    switches[i].init();
  }
}

void readSwitches() {
  for (int i = 0; i < switchCount; i++) {
    switches[i].read();
  }
}

void initKnobs() {
  for (int i = 0; i < knobCount; i++) {
    knobs[i].init();
  }
}

void readKnobs() {
  for (int i = 0; i < knobCount; i++) {
    knobs[i].read();
  }
}

