#include <Arduino.h>
#include "program.h"
Program program = Program();
void setup() {
  Serial.begin(9600);
  delay( 3000 ); // power-up safety delay
  program.init();
}

void loop() {
  program.update();
}

