#include "Motor.hpp"

const int MOTOR_PIN = 9;

Motor motor1(MOTOR_PIN);

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  motor1.init();
}

void loop() {
  motor1.setSpeed(2000);
  delay(1000);
}
