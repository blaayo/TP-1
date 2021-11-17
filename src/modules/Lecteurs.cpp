#include "Lecteurs.h"

String Lecteurs::LectureRFID(Rfid *rfid)
{
    return rfid->scanUID();
};
bool Lecteurs::verifRFID(Rfid *rfid)
{
    if (!rfid->detectPresent())
        return false;
    if (!rfid->readCard())
        return false;
    return true;
};