#include "Avertisseurs.h"

void Avertisseurs::advertByLed(Led *led, bool state)
{
    switch (state)
    {
    case 1:
        led->on();
        break;

    default:
        led->off();
        break;
    }
};
void Avertisseurs::advertByBuzzer(Buzzer *buzzer, int state)
{
    switch (state)
    {
    case 1:
        buzzer->makeSound(1200, 100);
        delay(125);
        buzzer->makeSound(1200, 100);
        break;

    default:
        buzzer->makeSound(200, 750);
        break;
    }
};
void Avertisseurs::advertByLcd(Lcd *lcd, int state)
{
    lcd->clear();
    switch (state)
    {
    case 1:
        lcd->write("ACCES AUTORISE", "");
        break;
    case 2:
        lcd->write("ACCES REFUSE", "");
        break;
    case 3:
        lcd->write("Scannez votre", "carte ou badge..");
        break;

    default:
        lcd->write("Dispositif", "d'identification");
        delay(3000);
        break;
    }
};