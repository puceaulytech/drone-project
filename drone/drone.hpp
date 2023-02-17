#include "Arduino.h"
#ifndef DRONE_HPP
#define DRONE_HPP
#include "Servo.h"
#include "Motor.hpp"
#include "Barometer.hpp"
#include "Vector3.h"

class Drone
{

public:
    int[2] constrainsL = [-20,20];
    int[2] constrainsR = [-20,20];
    int[2] constrainsY = [-20,20];
    float gainR, gainL, gainY;
    Barometer baro;
    Motor motor;
    float throttle;
    Servo RudderL, RudderR, RudderY;
    float yaw, pitch, roll;
    float lat, lon, speed, gps_altitude;
    float altitude;
    float temp;
    bool automatic;
    Drone(int motorpin, int gpsRx, int gpsTx, int rLpin, int rRpin, int rYpin);
    void Init();
    void update();

    private : 
    //RESPONSES GROUPS    YAW PITCH ROLL
    Vector3 RYaw = Vector3(1,0,0);
    Vector3 RPitch = Vector3(0,1,0);
    Vector3 RRoll = Vector3(0,0,1);


    //RESPONSE SERVOS
  Vector3 CYaw = Vector3(1,0,0);
  Vector3 CPitch = Vector3(0,1,1);
  Vector3 CRoll = Vector3(0,-1,1);

    //PINS
int m_motorpin,  m_gpsRx,  m_gpsTx,  m_rLpin,  m_rRpin, m_rYpin;

    
    void updateResponse();
    
};
#endif