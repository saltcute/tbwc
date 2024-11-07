#include <Servo.h>
#define SERVO_PIN 9

Servo servo;

void initServoMotor()
{
    servo.attach(SERVO_PIN);
}

void setServoAngle(int degree)
{
    servo.write(degree);
}