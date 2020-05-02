#ifndef PUMP_H
#define PUMP_H

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class Pump
{

public:
  int pumpRunTimeMillis = 1000;
  byte pumpPowerPercent = 100; // Процент мощноти от 0 до 100(потом переводится в скважность от 0 до 254);

private:
  int pinPumpPower; //Pin поодерживающий ШИМ, например D3 или D11

public:
  Pump(int pinPumpPower, int pumpRunTimeMillis, byte pumpPowerPercent)
  {
    this->pinPumpPower = pinPumpPower;
    pinMode(pinPumpPower, OUTPUT);

    this->pumpRunTimeMillis = pumpRunTimeMillis;
    this->pumpPowerPercent = pumpPowerPercent;
  };

  Pump(int pinPumpPower)
  {
    this->pinPumpPower = pinPumpPower;
    pinMode(pinPumpPower, OUTPUT);
  };

  ~Pump(){};

  void watering(byte pumpPowerProcent, int timeMillis)
  {
    byte goodness = percentToGoodness(pumpPowerProcent); //Преобразовать процент в сигнал-скважность от 0 до 254

    Serial.println("Полив начат");
    analogWrite(pinPumpPower, goodness); //Включить на шим двигатель с введеной скважностью
    delay(timeMillis);                   //оставить на это время включенным
    digitalWrite(pinPumpPower, LOW);     //Выключить двигатель
    Serial.println("Полив закончен");
  }

  void watering()
  {
    watering(pumpPowerPercent, pumpRunTimeMillis);
  }

private:
  byte percentToGoodness(byte power)
  {
    return map(power, 0, 100, 0, 254);
  }
};

#endif