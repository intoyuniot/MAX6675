// this library is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple
//Adapted for IntoRobot by Robin, Sept 19, 2015

#include "MAX6675.h"



MAX6675::MAX6675(int8_t _sclk, int8_t _cs, int8_t _miso)
{
    sclk = _sclk;
    cs = _cs;
    miso = _miso;

    //define pin modes
    pinMode(cs, OUTPUT);
    pinMode(sclk, OUTPUT);
    pinMode(miso, INPUT);

    digitalWrite(cs, HIGH);
}
double MAX6675::readCelsius(void)
{
    uint16_t v;

    digitalWrite(cs, LOW);
    delay(1);

    v = spiread();
    v <<= 8;
    v |= spiread();

    digitalWrite(cs, HIGH);
    if (v & 0x4) {
        // uh oh, no thermocouple attached!
        return NAN;
        //return -100;
    }
    v >>= 3;
    return v*0.25;
}

double MAX6675::readFahrenheit(void)
{
    return readCelsius() * 9.0/5.0 + 32;
}

byte MAX6675::spiread(void)
{
    int i;
    byte d = 0;

    for (i=7; i>=0; i--)
    {
        digitalWrite(sclk, LOW);
        delay(1);
        if (digitalRead(miso))
        {
            //set the bit to 0 no matter what
            d |= (1 << i);
        }
        digitalWrite(sclk, HIGH);
        delay(1);
    }
    return d;
}
