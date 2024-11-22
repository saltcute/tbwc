#include "movementBasic.hpp"

#define MOVEMENT_FORWARD 1
#define MOVEMENT_BACKWARD 2
// #define MOVEMENT_ROTATE_CW 3
// #define MOVEMENT_ROTATE_CCW 4
#define MOVEMENT_STATIONARY 5

int currentMovement = MOVEMENT_STATIONARY;

/**
 * Move the wheelchair forward.
 * 
 * @param speed The speed for the wheelchair to move at.
 */
void gearForward(int speed) {
  currentMovement = MOVEMENT_FORWARD;
  setLeftMotorCCW(speed);
}

/**
 * Move the wheelchair backward.
 * 
 * @param speed The speed for the wheelchair to move at.
 */
void gearBackward(int speed) {
  currentMovement = MOVEMENT_BACKWARD;
  setLeftMotorCW(speed);
}

/**
 * Stop giving power to motors.
 */
void gearNeutral() {
  setLeftMotorStop();
}

/**
 * Stop the wheelchair. Simulates braking.
 */
void brake() {
  switch (currentMovement) {
    case MOVEMENT_FORWARD:
      {
        setLeftMotorCW(currentSpeedLeft);
        delay(220);
        gearNeutral();
        break;
      }
    case MOVEMENT_BACKWARD:
      {
        setLeftMotorCCW(currentSpeedLeft);
        delay(220);
        gearNeutral();
        break;
      }
    default:
      break;
  }
}
