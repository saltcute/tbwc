#include "movements.hpp"

void setup() {
  // put your setup code here, to run once:
  initializeMotors();
}

void loop() {
  gearForward(120);
  delay(1000);

  brake();
  delay(2000);

  gearBackward(120);
  delay(1000);

  gearNeutral();
  delay(3000);
}
