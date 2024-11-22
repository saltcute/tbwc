#define ENA 11
#define INPUT_L_1 12
#define INPUT_L_2 13

#define ENB 5
#define INPUT_R_1 7
#define INPUT_R_2 6

int currentSpeedLeft = 0;
int currentSpeedRight = 0;

/**
 * Set the speed of motor L.
 * 
 * @param speed The designated speed.
 */
void setLeftMotorSpeed(int speed) {
  currentSpeedLeft = speed;
  analogWrite(ENA, speed);
}

/**
 * Set the speed of motor R.
 * 
 * @param speed The designated speed.
 */
void setRightMotorSpeed(int speed) {
  currentSpeedRight = speed;
  analogWrite(ENB, speed);
}

/**
 * Set motor L to spin clockwise.
 * 
 * @param speed The designated speed of the motor.
 */
void setLeftMotorCW(int speed) {
  digitalWrite(INPUT_L_1, HIGH);
  digitalWrite(INPUT_L_2, LOW);
  setLeftMotorSpeed(speed);
}

/**
 * Set motor L to spin counter-clockwise.
 * 
 * @param speed The designated speed of the motor.
 */
void setLeftMotorCCW(int speed) {
  digitalWrite(INPUT_L_1, LOW);
  digitalWrite(INPUT_L_2, HIGH);
  setLeftMotorSpeed(speed);
}

/**
 * Set motor L to stop giving power.
 * 
 * Note: this only stop the motor from getting power, but does not actually stop the motor from spinning!
 */
void setLeftMotorStop() {
  digitalWrite(INPUT_L_1, LOW);
  digitalWrite(INPUT_L_2, LOW);
  setLeftMotorSpeed(0);
}

/**
 * Set motor R to spin clockwise.
 * 
 * @param speed The designated speed of the motor.
 */
void setRightMotorCW(int speed) {
  digitalWrite(INPUT_R_1, HIGH);
  digitalWrite(INPUT_R_2, LOW);
  setRightMotorSpeed(speed);
}
/**
 * Set motor R to spin counter-clockwise.
 * 
 * @param speed The designated speed of the motor.
 */
void setRightMotorCCW(int speed) {
  digitalWrite(INPUT_R_1, LOW);
  digitalWrite(INPUT_R_2, HIGH);
  setRightMotorSpeed(speed);
}

/**
 * Set motor R to stop giving power.
 * 
 * Note: this only stop the motor from getting power, but does not actually stop the motor from spinning!
 */
void setRightMotorStop() {
  digitalWrite(INPUT_R_1, LOW);
  digitalWrite(INPUT_R_2, LOW);
  setRightMotorSpeed(0);
}

/**
 * Initialize DC motor pins.
 */
void initDCMotors() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(INPUT_L_1, OUTPUT);
  pinMode(INPUT_L_2, OUTPUT);
  pinMode(INPUT_R_1, OUTPUT);
  pinMode(INPUT_R_2, OUTPUT);
}
