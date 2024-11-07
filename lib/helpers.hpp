#include "movements.hpp"
#include "servo.hpp"
#include "IRSensor.hpp"

void initTBWC() {
    initDCMotors();
    initServoMotor();
}