#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include "modules/Avertisseurs.h"
#include "modules/Lecteurs.h"

/* MODULES */
Avertisseurs *avertisseur;
Lecteurs     *lecteur;

/* COMPOSANTS */
Buzzer  *leBuzzer;
Led     *ledRouge;
Led     *ledVerte;
Lcd     *afficheurLcd;
Rfid    *lecteurRFID;


void setup()
{
  SPI.begin();
  avertisseur   = new Avertisseurs();
  lecteur       = new Lecteurs();   
  leBuzzer      = new Buzzer(8);
  ledRouge      = new Led(15);
  ledVerte      = new Led(14);
  afficheurLcd  = new Lcd(7, 6, 5, 4, 3, 2);
  lecteurRFID   = new Rfid(10, 9);

  avertisseur->advertByLcd(afficheurLcd,0);  
}

void loop()
{
  avertisseur->advertByLcd(afficheurLcd,3);

  if ( lecteur->verifRFID(lecteurRFID) )
  {
    if ( lecteur->LectureRFID(lecteurRFID) == "63 28 6B 0C")
    {
      avertisseur->advertByLcd(afficheurLcd,1); 
      avertisseur->advertByLed(ledVerte,1);
      avertisseur->advertByBuzzer(leBuzzer,1);
      delay(2000);
      avertisseur->advertByLed(ledVerte,0);
    }
    else
    {
      avertisseur->advertByLcd(afficheurLcd,2);
      avertisseur->advertByLed(ledRouge,1);
      avertisseur->advertByBuzzer(leBuzzer,0);
      delay(2000);
      avertisseur->advertByLed(ledRouge,0);
    }
  }
}