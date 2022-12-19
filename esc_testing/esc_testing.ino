#include "Motor.hpp"
#include <PID_v1.h>

const int MOTOR_PIN = 10;

Motor motor1(MOTOR_PIN);

double Setpoint, Input, Output;

double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  motor1.init();
}

void loop() {
  motor1.setSpeed(1000);
  delay(1000);
}
