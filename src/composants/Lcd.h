#include <Arduino.h>
#include <LiquidCrystal.h>

class Lcd
{
private:
    LiquidCrystal *lcd;

public:
    Lcd(int e, int rs, int d4, int d5, int d6, int d7);
    void write(String firstLine, String lastLine);
    void clear();
};
