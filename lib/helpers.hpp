#include "movements.hpp"
#include "servo.hpp"

/**
 * A wrapper function that handles all the initialization process.
 */
void initTBWC() {
    initDCMotors();
    initServoMotor();
}