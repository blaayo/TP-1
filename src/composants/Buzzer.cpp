#include "Buzzer.h"

Buzzer::Buzzer(int pin)
{
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
};

void Buzzer::makeSound(int a, int b)
{
    tone(this->pin, a, b);
};