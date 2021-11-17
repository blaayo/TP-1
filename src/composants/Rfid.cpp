#include "Rfid.h"

Rfid::Rfid(int sda, int rst)
{
  this->rfid = new MFRC522(sda, rst);
  this->rfid->PCD_Init();
};

bool Rfid::detectPresent()
{
  if (this->rfid->PICC_IsNewCardPresent())
    return true;
  return false;
};

bool Rfid::readCard()
{
  if (this->rfid->PICC_ReadCardSerial())
    return true;
  return false;
};

String Rfid::scanUID()
{
  String UID = "";
  for (byte i = 0; i < this->rfid->uid.size; i++)
  {
    UID.concat(String(this->rfid->uid.uidByte[i] < 0x10 ? " 0" : " "));
    UID.concat(String(this->rfid->uid.uidByte[i], HEX));
  }
  UID.toUpperCase();
  return UID.substring(1);
};