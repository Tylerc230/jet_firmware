#include "leds.h"
#include "inputs.h"
struct Program {
  AirplaneLEDs airplane = AirplaneLEDs();
  Inputs inputs = Inputs();
  void init();
  void update();

};
