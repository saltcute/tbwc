#include "helpers.hpp"

#define MODE_SELECTOR_PIN 5

void setup()
{
  initTBWC();
}

#define STAGE_ORIGIN 0
#define STAGE_FORWARD 1
#define STAGE_BACKWARD 2
#define STAGE_END 3

int stage = STAGE_ORIGIN;

int speed = 250;

int forwardStartTime;

/**
 * in ms.
 */
const int RUN_PERIOD = 20000;

void loop()
{
  switch (stage)
  {
  case STAGE_ORIGIN:
  {
    gearForward(speed);
    forwardStartTime = millis();
    stage = STAGE_FORWARD;
    break;
  }
  case STAGE_FORWARD:
  {
    // The wheel chair moves forward forever.
    
    // if (millis() - forwardStartTime > RUN_PERIOD)
    // {
    //   brake();
    //   stage = STAGE_END;
    // }
    break;
  }
  }
}
