#include <Arduino.h>

class Buzzer
{
private:
    int pin;

public:
    Buzzer(int pin);
    void makeSound(int a, int b);
};