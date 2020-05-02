#include <Arduino.h>
#include <Pump.h>

int pinButton = 2;
int pinPotentiometer = A0;
int pinVccPump = 3;

Pump pump1(pinVccPump);

void setup() {
  Serial.begin(9600);
  pinMode(pinButton, INPUT);
  initPump1();
}

void loop() {
  if (digitalRead(pinButton)) {
    int powerProcent = calculateAnalogInProcent(analogRead(pinPotentiometer));
    pump1.setPowerPercent(powerProcent);
    pump1.watering();
  }

  delay(300);
}

void initPump1(){
  pump1 = Pump(pinVccPump);
  pump1.setPumpRunTimeMillis(5000);
  pump1.setPowerPercent(100);
}

int calculateAnalogInProcent(int analogSignal){
  
  return map(analogSignal,0, 1024, 0, 100); //907 заменить на считанное своё(максимальное значение, которые отдаёт потенцометр
}
