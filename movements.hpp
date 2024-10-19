#include "movementBasic.hpp"

#define MOVEMENT_FORWARD 1
#define MOVEMENT_BACKWARD 2
// #define MOVEMENT_ROTATE_CW 3
// #define MOVEMENT_ROTATE_CCW 4
#define MOVEMENT_STATIONARY 5


/**
 * 
 */
int currentMovement = MOVEMENT_STATIONARY;
void gearForward(int speed) {
  currentMovement = MOVEMENT_FORWARD;
  setLeftMotorCCW(speed);
  setRightMotorCCW(speed);
}

void gearBackward(int speed) {
  currentMovement = MOVEMENT_BACKWARD;
  setLeftMotorCW(speed);
  setRightMotorCW(speed);
}

void gearNeutral() {
  setLeftMotorStop();
  setRightMotorStop();
}

void brake() {
  switch (currentMovement) {
    case MOVEMENT_FORWARD:
      {
        setLeftMotorCW(currentSpeedLeft);
        setRightMotorCW(currentSpeedRight);
        delay(220);
        gearNeutral();
        break;
      }
    case MOVEMENT_BACKWARD:
      {
        setLeftMotorCCW(currentSpeedLeft);
        setRightMotorCCW(currentSpeedRight);
        delay(220);
        gearNeutral();
        break;
      }
    default:
      break;
  }
}
