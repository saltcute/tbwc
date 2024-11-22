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

int speed = 200;

int forwardStartTime;

/**
 * in ms.
 */
const int RUN_PERIOD = 4500;

void loop()
{
    switch (stage)
    {
    case STAGE_ORIGIN:
    {
        // Resets the servo motor to the initial position.
        setServoAngle(0);
        gearForward(speed);
        forwardStartTime = millis();
        stage = STAGE_FORWARD;
        break;
    }
    case STAGE_FORWARD:
    {
        // After moving forward for a designated time.
        if (millis() - forwardStartTime > RUN_PERIOD)
        {
            // The wheel chair will stop, wait 1000ms
            brake();
            delay(1000);
            // And then trigger the launching mechanism with the servo motor.
            setServoAngle(180);
            delay(1500);
            setServoAngle(0);
            stage = STAGE_END;
        }
        break;
    }
    }
}
