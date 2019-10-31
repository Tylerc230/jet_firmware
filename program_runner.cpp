#include "program_runner.h"
#include "colorutils.h"
#include "constants.h"
#include "programs/ColorProgram.h"
#include "programs/RainProgram.h"
#define NUM_PROG 2


void ProgramRunner::init() {
  inputs.init();
  airplane.init();
  inputs.progSelect.max = NUM_PROG;
}

void ProgramRunner::update() {
  inputs.read();
  int selection = inputs.progSelect.pos;
  if (selection != currentProgramIndex) {
    if (currentProgram != NULL) {
      delete currentProgram;
    }
    currentProgram = createProgram(selection);
    currentProgramIndex = selection;
    currentProgram->init(inputs, airplane);
  }
  currentProgram->update(inputs, airplane);
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

Program * ProgramRunner::createProgram(uint8_t progIndex) {
  switch (progIndex) {
    case 0:
      return new RainProgram();
    case 1:
      return new ColorProgram();

  };
}


