#include <Arduino.h>
#include "composants/Buzzer.h"
#include "composants/Lcd.h"
#include "composants/Led.h"

class Avertisseurs
{
public:
    void advertByLed(Led *led, bool state);
    void advertByBuzzer(Buzzer *buzzer, int state);
    void advertByLcd(Lcd *lcd, int state);
};