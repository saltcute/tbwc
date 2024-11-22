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

const int speed = 250;

int forwardStartTime;

/**
 * The time the wheel chair goes forward in ms.
 */
const int RUN_PERIOD = 6500;
/**
 * The time the wheel chair slows down in the later part of going forward.
 */
const int SLOW_DOWN_PERIOD = 700;

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
    int currentRunTime = millis() - forwardStartTime;
    if (currentRunTime > RUN_PERIOD)
    {
      // brake();
      // The wheel chair will move backwards forever after reaching the time limit.
      gearBackward(speed);
      stage = STAGE_BACKWARD;
    } else if (RUN_PERIOD - (currentRunTime) < SLOW_DOWN_PERIOD) {
      int progress = SLOW_DOWN_PERIOD - (RUN_PERIOD - (currentRunTime));
      // The wheel chair will slow down to 70% of the designated speed near the end.
      gearForward(speed * (0.7 + 0.3 * progress / SLOW_DOWN_PERIOD));
    }
    break;
  }
  case STAGE_BACKWARD:
  {
    // brake();
    stage = STAGE_END;
    break;
  }
  }
}
