#include "Program.h"
#include "colorutils.h"
#include "constants.h"
struct Program {
  virtual void init() = 0;
  virtual void update(Inputs & inputs, AirplaneLEDs & airplane) = 0;
};

struct ColorProgram: Program {
  CRGBPalette16 palette;
  ColorProgram(CRGBPalette16 palette) : palette(palette) {}
  virtual void init() {

  }

  virtual void update(Inputs & inputs, AirplaneLEDs & airplane) {

  }
};

void ProgramRunner::init() {
  inputs.init();
  airplane.init();
}

void ProgramRunner::update() {
  inputs.read();
  if (inputs.progSelect.pos != currentProgramIndex) {
    if (currentProgram != NULL) {
      delete currentProgram;
    }
    currentProgram = createProgram(inputs.progSelect.pos);
    currentProgramIndex = inputs.progSelect.pos;
    currentProgram->init();
  }
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

Program * ProgramRunner::createProgram(uint8_t progIndex) {
  switch (progIndex) {
    case 0:
      return new ColorProgram(RainbowColors_p);

  };
}


