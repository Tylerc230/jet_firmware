#include "Program.h"
#include "colorutils.h"
#include "constants.h"
struct Program {
  virtual void init(Inputs & inputs, AirplaneLEDs & airplane) = 0;
  virtual void update(Inputs & inputs, AirplaneLEDs & airplane) = 0;
};

struct ColorProgram: Program {
  CRGBPalette16 palette;
  ColorProgram(CRGBPalette16 palette) : palette(palette) {}
  virtual void init(Inputs & inputs, AirplaneLEDs & airplane) {
    airplane.clearLEDs();
  }

  virtual void update(Inputs & inputs, AirplaneLEDs & airplane) {
    airplane.tail.leds[0] = CRGB::Red;
  }
};

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


