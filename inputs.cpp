#include "inputs.h"
void Switch::init() {
  pinMode(pin, INPUT_PULLUP);
}

void Switch::read() {
  state = digitalRead(pin);
}

void EncoderKnob::init() {
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, LOW);
}

void EncoderKnob::read() {
  int p0 = digitalRead(pin0);
  int p1 = digitalRead(pin1);
  if (pin0LastReading != p0) {
    if (p1 == p0) {
      pos--;
    } else {
      pos++;
    }
  }
  pin0LastReading = p0;
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


