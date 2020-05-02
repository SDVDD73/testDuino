#ifndef BUTTON_H
#define BUTTON_H

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class Button{
private:
    byte pinButton;

public:
    Button(byte pinButton) //в конструкторе необходимо указать пин который отвечает за кнопку Button button1(номер_пина_кнопки); После этого запишется переменная класса ссылающаяся на пин кнопки и при помощи pinMode кнопка инициализируется в ардуино
    {
        this->pinButton = pinButton;
        pinMode(pinButton, INPUT_PULLUP);
    }

    boolean isPressed()//Метод для проверке нажата ли кнопка
    {
        boolean isPressed = false;

        if(digitalRead(pinButton) == HIGH){//Кнопка может быть нажата или просто наводки, поэтому мы должны немножго подождать delay() и проверить нажата ли она реально
        delay(5);//Немного подождём
           isPressed = digitalRead(pinButton);//Запишем реально ли кнопка нажата
           Serial.println(isPressed);
        }

        return isPressed;
    }
};

#endif