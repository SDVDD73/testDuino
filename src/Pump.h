#ifndef PUMP_H
#define PUMP_H

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class Pump {
  public:
    int pinPumpPower;
    int pumpRunTimeMillis = 1000;
    byte pumpPower = 254; // 0 .. 254

    Pump(int pinPumpPower, int pumpRunTimeMillis, byte pumpPower) {
      pinPumpPower = pinPumpPower;
	  pinMode(pinPumpPower, OUTPUT);
	  
      pumpRunTimeMillis = pumpRunTimeMillis;
      pumpPower = pumpPower;
    };

    Pump(int pinPumpPower){
      pinPumpPower = pinPumpPower;
    };

    Pump() = default;

    ~Pump() {};

    void watering(){
	  Serial.println("Полив начат");
      analogWrite(pinPumpPower, pumpPower);
      delay(pumpRunTimeMillis);
      digitalWrite(pinPumpPower, LOW);
	  Serial.println("Полив закончен");
    }

    void setPowerPercent(byte power){
      pumpPower = map(power, 0, 100, 0, 254);
      Serial.println(pumpPower);
    }
	
	void setPumpRunTimeMillis(int pumpRunTimeMillisInput){
      pumpRunTimeMillis = pumpRunTimeMillisInput;
    }

};

#endif