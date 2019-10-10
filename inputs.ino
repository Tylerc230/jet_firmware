#include "constants.h"
#define COUNT(array) sizeof(array)/sizeof(array[0])
const int switchPins[] = {SWITCH_A_PIN, SWITCH_B_PIN, SWITCH_C_PIN};
const int switchCount = COUNT(switchPins);
int switchState [switchCount];
struct EncoderKnob {

  EncoderKnob(uint8_t p0, uint8_t p1): pin0(p0), pin1(p1) { }
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
    pinMode(switchPins[i], INPUT_PULLUP);
    digitalWrite(switchPins[i], HIGH);
  }
}

void readSwitches() {
  for (int i = 0; i < switchCount; i++) {
    int state = digitalRead(switchPins[i]);
    switchState[i] = state;
  }
}

void initKnobs() {
  for (int i = 0; i < knobCount; i++) {
    EncoderKnob knob = knobs[i];
    pinMode(knob.pin0, INPUT);
    pinMode(knob.pin1, INPUT);
  }
}

void readKnobs() {
  for (int i = 0; i < knobCount; i++) {
    EncoderKnob & knob = knobs[i];
    int pin0 = digitalRead(knob.pin0);
    if (knob.pin0LastReading == LOW && pin0 == HIGH) {
      int pin1 = digitalRead(knob.pin1);
      if (pin1 == LOW) {
        knob.pos--;
      } else {
        knob.pos++;
      }
    }
    knob.pin0LastReading = pin0;
  }
}

