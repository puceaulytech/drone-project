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