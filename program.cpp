#include "Program.h"
void Program::init() {
  inputs.init();
  airplane.init();
}

void Program::update() {
  inputs.read();
}
