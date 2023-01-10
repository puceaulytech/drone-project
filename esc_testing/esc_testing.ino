// #include "Motor.hpp"
// #include <PID_v1.h>
#include "Receiver.hpp"

// const int MOTOR_PIN = 10;

// Motor motor1(MOTOR_PIN);

// double Kp=2, Ki=5, Kd=1;
// PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

Receiver receiver;

void setup() {
  // pinMode(MOTOR_PIN, OUTPUT);
  // motor1.init();
  Serial.begin(9600);
  pinMode(3, INPUT);
}

void loop() {
  //motor1.setSpeed(1000);
  //delay(1000);
  receiver.update(3);
  delay(2);

  Serial.println(receiver.getChannel(3));
}
