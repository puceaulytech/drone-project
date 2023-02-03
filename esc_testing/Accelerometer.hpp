#ifndef ACCELEROMETER_HPP
#define ACCELEROMETER_HPP

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

class Accelerometer {
  public:
    struct Coords {
      float x, y, z;
    };

    struct Result {
      Coords acceleration, gyro;
      float temperature;
    };

    Accelerometer() = default;

    void init() {
      mpu.begin();
      mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
      mpu.setGyroRange(MPU6050_RANGE_500_DEG);
      mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    }

    Result get() const {
      Result r;

      sensors_event_t a, g, temp;
      mpu.getEvent(&a, &g, &temp);

      r.acceleration.x = a.acceleration.x;
      r.acceleration.y = a.acceleration.y;
      r.acceleration.z = a.acceleration.z;

      r.gyro.x = g.gyro.x;
      r.gyro.y = g.gyro.y;
      r.gyro.z = g.gyro.z;

      r.temperature = temp.temperature;

      return r;
    }

  private:
    Adafruit_MPU6050 mpu;
};

#endif