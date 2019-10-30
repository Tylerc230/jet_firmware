#include "program_runner.h"
#include "colorutils.h"
#include "constants.h"
#include "programs/ColorProgram.h"


void ProgramRunner::init() {
  inputs.init();
  airplane.init();
}

void ProgramRunner::update() {
  inputs.read();
  int selection = 0;//inputs.progSelect.pos % 0;
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
      return new ColorProgram(RainbowColors_p);

  };
}


