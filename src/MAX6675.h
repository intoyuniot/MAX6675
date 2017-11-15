// this library is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple
//Adapted for IntoRobot by Robin, Sept 19, 2015

#include "Arduino.h"
#include <math.h>

class MAX6675
{
    public:
        MAX6675(int8_t _sclk, int8_t _cs, int8_t _miso);
        double readCelsius(void);
        double readFahrenheit(void);
        // For compatibility with older versions:
        double readFarenheit(void) { return readFahrenheit(); }

    private:
        int8_t sclk, miso, cs;
        uint8_t spiread(void);
};
