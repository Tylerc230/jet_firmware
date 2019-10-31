#include "inputs.h"
void Switch::init() {
  pinMode(pin, INPUT_PULLUP);
}

void Switch::read() {
  lastState = state;
  state = digitalRead(pin);
}

bool Switch::didChange() {
  return state != lastState;
}

bool Switch::isPressed() {
  return state == LOW;
}

void EncoderKnob::init() {
  enc.write(pos);
}

void EncoderKnob::read() {
  int total = enc.read() / 4;
  if (total < 0) {
    total = max - 1;
  }
  pos = (total) % max;
}

void Inputs::init() {
  horn.init();
  s1.init();
  s2.init();
  progSelect.init();
  progMod.init();
}

void Inputs::read() {
  horn.read();
  s1.read();
  s2.read();
  progSelect.read();
  progMod.read();
}


