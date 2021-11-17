#include <Arduino.h>
#include "composants/Rfid.h"

class Lecteurs
{
public:
    String LectureRFID(Rfid *rfid);
    bool verifRFID(Rfid *rfid);
};

