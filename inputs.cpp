#include "inputs.h"
void Switch::init() {
  pinMode(pin, INPUT_PULLUP);
}

void Switch::read() {
  state = digitalRead(pin);
}

void EncoderKnob::init() {
  enc.write(pos);
}

void EncoderKnob::read() {
  pos = enc.read();
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


