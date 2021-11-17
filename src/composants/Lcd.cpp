#include "Lcd.h"

Lcd::Lcd(int e, int rs, int d4, int d5, int d6, int d7)
{
    this->lcd = new LiquidCrystal(e, rs, d4, d5, d6, d7);
    this->lcd->begin(16, 2);
};
void Lcd::write(String firstLine, String lastLine)
{
    this->lcd->setCursor(0, 0);
    this->lcd->print(firstLine);
    this->lcd->setCursor(0, 1);
    this->lcd->print(lastLine);
};
void Lcd::clear()
{
    this->lcd->clear();
};