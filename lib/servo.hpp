#include <Servo.h>
#define SERVO_PIN 9

Servo servo;

/**
 * Initialize the servo motor.
 */
void initServoMotor()
{
    servo.attach(SERVO_PIN);
}

/**
 * Turn the servo motor to a angle.
 * 
 * @param degree The angle to turn to.
 */
void setServoAngle(int degree)
{
    servo.write(degree);
}