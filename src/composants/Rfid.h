#include <Arduino.h>
#include <MFRC522.h>

class Rfid
{
private:
    MFRC522 *rfid;

public:
    Rfid(int sda, int rst);
    bool detectPresent();
    bool readCard();
    String scanUID();
};
