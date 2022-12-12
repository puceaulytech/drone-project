#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Servo.h>

class Motor {
  public:
    inline Motor(int pin);
    inline void init();

    inline void setSpeed(int speed);
  private:
    Servo m_servo;
    int m_pin;
};

Motor::Motor(int pin) : m_servo(), m_pin(pin) {}

void Motor::init() {
  m_servo.attach(m_pin, 1000,2000);
  delay(10);
  m_servo.writeMicroseconds(1000);
  delay(1000);
}

void Motor::setSpeed(int speed) {
  m_servo.writeMicroseconds(speed);
}

#endif
