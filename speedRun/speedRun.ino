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

int forwardStartTime, backwardStartTime, singleRunInterval;

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
    if (!isIRDetected())
    {
      brake();
      singleRunInterval = millis() - forwardStartTime;
      backwardStartTime = millis();
      gearBackward(speed);
      stage = STAGE_BACKWARD;
    }
    break;
  }
  case STAGE_BACKWARD:
  {
    if (millis() - backwardStartTime > singleRunInterval)
    {
      brake();
      stage = STAGE_END;
    }
    break;
  }
  }
}
