//On ajoute les differentes library

#include <DS1307RTC.h>

#include <Time.h>

#include <Wire.h>



int startup = 0;



void setup() //On initialise nos leds des pins 2 a 12

{

  Serial.begin(9600);



  for(int n = 2; n != 13; n++)

  {

    pinMode(n, OUTPUT);

  }

}



void minutes() //On convertit les minutes en binaire et on associe les leds correspondantes

{

  tmElements_t tm;



  if (RTC.read(tm)) {

    int min = tm.Minute;

    Serial.print(tm.Minute);

    int restem = 0;

    int ledm = 12;



    for(min = min; min >= 1; ledm--)

    {

      restem = min % 2;

      min = min / 2;



      if (restem == 1) {

        digitalWrite(ledm, HIGH);

      }

      else {

        digitalWrite(ledm, LOW);

      }

    }

  }

}



void hours() //On convertit les heures en binaire et on associe les leds correspondantes

{

  tmElements_t tm;

  if (RTC.read(tm)) {

    int h = tm.Hour;

    Serial.println(tm.Hour);

    int resteh = 0;

    int ledh = 6;



    for(h = h; h >= 1; ledh--)

    {

      resteh = h % 2;

      h = h / 2;



      if (resteh == 1) {

        digitalWrite(ledh, HIGH);

      }

      else {

        digitalWrite(ledh, LOW);

      }

    }

  }

}

void loop() //On lance le programme

{

    minutes();

    hours();

    delay(200); //On maj les heures et les minutes

}
