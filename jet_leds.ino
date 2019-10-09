#include <FastLED.h>
const int switchPins[] = {2,3,4,6,7,8,9,10,11,12};
const int switchCount = sizeof(switchPins)/sizeof(switchPins[0]);
int switchState [switchCount];
void setup() {
  Serial.begin(9600);
  initSwitches();
}

void loop() {
  readSwitches();
  for (int i = 0; i < switchCount; i++) {
    Serial.print(switchState[i]);
  }
  Serial.println();
}

void readSwitches() {
  for (int i = 0; i < switchCount; i++) {
    int state = digitalRead(switchPins[i]);
    switchState[i] = state;
  }
}

void initSwitches() {
  for (int i = 0; i < switchCount; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
    digitalWrite(switchPins[i], HIGH);
  }
}
