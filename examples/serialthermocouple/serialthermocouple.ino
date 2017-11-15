//热电偶传感器

#include <MAX6675.h>

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;

void setup()
{
    pinMode(vccPin, OUTPUT);
    digitalWrite(vccPin, HIGH);
    pinMode(gndPin, OUTPUT);
    digitalWrite(gndPin, LOW);
    Serial.begin(115200);
    Serial.println("MAX6675 test");
    //等待器件稳定
    delay(500);
}

void loop()
{
    // 获取当前温度
    Serial.print("C = ");
    Serial.println(thermocouple.readCelsius());//摄氏度
    Serial.print("F = ");
    Serial.println(thermocouple.readFahrenheit()); //华氏度
    delay(1000);
}
