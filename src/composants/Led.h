#include <Arduino.h>

class Led
{
private:
    int pin;

public:
    Led(int pin);
    void on();
    void off();
};