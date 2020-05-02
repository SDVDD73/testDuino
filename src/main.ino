#include <Arduino.h>
#include <Pump.h>
#include <Button.h>

int pinVccPump = 3;

Button button1(7);

int pinPotentiometer = A0;

Pump pump(pinVccPump);

void setup()
{
  Serial.begin(9600);

  TCCR2B = 0b00000001;//Сделаем шим на D3 и D11 пинах 31,4кГц (Нужны обе строчки)
  TCCR2A = 0b00000001;//Сделаем шим на D3 и D11 пинах 31,4кГц (Нужны обе строчки)
}

void loop()
{
  if (button1.isPressed())
  {
    byte powerProcent = calculateAnalogInProcent(analogRead(pinPotentiometer));
    Serial.println(powerProcent);

    pump.watering(powerProcent, 5000);
  }
}


int calculateAnalogInProcent(int analogSignal)
{
  return map(analogSignal, 0, 1024, 0, 100); //907 заменить на считанное своё(максимальное значение, которые отдаёт потенцометр
}
