Durant cette séance j'ai testé les capteurs de pression/altitude et l'accéléromètre. L'avantage de ces deux modules est que ils utilisent tous les deux I2C, ce qui permet de les brancher facilement en parallèle aux ports SDA et SCL de l'arduino. J'ai aussi programmé des classes pour faciliter l'acquision des données de ces capteurs :

```cpp
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
```

```cpp
#ifndef BAROMETER_HPP
#define BAROMETER_HPP

#include <BMP280_DEV.h>

class Barometer {
  public:
    struct Result {
      bool ok;
      float temperature, pressure, altitude;
    };

    Barometer() = default;

    void init() {
      bmp280.begin();
      bmp280.setTimeStandby(TIME_STANDBY_2000MS);
      bmp280.startNormalConversion();
    }

    Result get() const {
      bool ok;
      float temperature, pressure, altitude;

      ok = bmp280.getMeasurements(temperature, pressure, altitude);

      return {ok, temperature, pressure, altitude};
    }

  private:
    BMP280_DEV bmp280;
};

#endif
```

Finalement, j'ai lancé l'impression des dernières pièces pour le drone.
