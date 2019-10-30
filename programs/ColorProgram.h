#ifndef INCLUDE_COLOR_PROGRAM
#define INCLUDE_COLOR_PROGRAM

#include "Program.h"
#include <FastLED.h>
struct ColorProgram: Program {
    ColorProgram(CRGBPalette16 palette) : palette(palette) { }
    virtual void init(Inputs & inputs, AirplaneLEDs & airplane);
    virtual void update(Inputs & inputs, AirplaneLEDs & airplane);
    CRGBPalette16 palette;
    int index = 0;
};

#endif
