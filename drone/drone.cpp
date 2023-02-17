#include "Arduino.h"
#include "drone.hpp"
Drone::Drone(int motorpin, int gpsRx, int gpsTx, int rLpin, int rRpin, int rYpin):motor(m_motorpin){
  m_motorpin = motorpin;
  m_gpsRx = gpsRx;
  m_gpsTx = gpsTx;
  m_rLpin = rLpin;
  m_rRpin = rRpin;
  m_rYpin = m_rYpin; 


}

void Drone::Init(){
  RudderL.attach(m_rLpin);
  RudderR.attach(m_rRpin);
  RudderY.attach(m_rYpin);
  motor.init();
  baro.init();





}
void Drone::update(){
  Vector3 total = RYaw + RPitch + RRoll;
  float angleL = map(total[0],-100,100,constrainsL[0],constrainsL[1]);
    RudderL.write(angleL);
  float angleR = map(total[1],-100,100,constrainsR[0],constrainsR[1]);
    RudderL.write(angleL);
  float angleY = map(total[2],-100,100,constrainsY[0],constrainsY[1]);
    RudderL.write(angleL);

}