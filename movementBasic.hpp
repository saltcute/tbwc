#define ENA 11
#define INPUT_L_1 12
#define INPUT_L_2 13

#define ENB 5
#define INPUT_R_1 7
#define INPUT_R_2 6

int currentSpeedLeft = 0;
int currentSpeedRight = 0;

void setLeftMotorSpeed(int speed) {
  currentSpeedLeft = speed;
  analogWrite(ENA, speed);
}

void setRightMotorSpeed(int speed) {
  currentSpeedRight = speed;
  analogWrite(ENB, speed);
}

void setLeftMotorCW(int speed) {
  digitalWrite(INPUT_L_1, HIGH);
  digitalWrite(INPUT_L_2, LOW);
  setLeftMotorSpeed(speed);
}
void setLeftMotorCCW(int speed) {
  digitalWrite(INPUT_L_1, LOW);
  digitalWrite(INPUT_L_2, HIGH);
  setLeftMotorSpeed(speed);
}
void setLeftMotorStop() {
  digitalWrite(INPUT_L_1, LOW);
  digitalWrite(INPUT_L_2, LOW);
  setLeftMotorSpeed(0);
}

void setRightMotorCW(int speed) {
  digitalWrite(INPUT_R_1, HIGH);
  digitalWrite(INPUT_R_2, LOW);
  setRightMotorSpeed(speed);
}
void setRightMotorCCW(int speed) {
  digitalWrite(INPUT_R_1, LOW);
  digitalWrite(INPUT_R_2, HIGH);
  setRightMotorSpeed(speed);
}
void setRightMotorStop() {
  digitalWrite(INPUT_R_1, LOW);
  digitalWrite(INPUT_R_2, LOW);
  setRightMotorSpeed(0);
}

void initDCMotors() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(INPUT_L_1, OUTPUT);
  pinMode(INPUT_L_2, OUTPUT);
  pinMode(INPUT_R_1, OUTPUT);
  pinMode(INPUT_R_2, OUTPUT);
}
