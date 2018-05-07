/*
 * Setup variables and setup Papa Soundie library.
 */
int Red = A0;
int Blue = A1;
int buttonState1 = 0;
int buttonState2 = 0;
const int buttonPin1 = 10;
const int buttonPin2 = 11;
const int ledPin1 =  A0;
const int ledPin2 =  A1;
#include "SparkFun_PapaSoundie.h"
PapaSoundie sfx = PapaSoundie();


void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin2, INPUT_PULLUP);
  sfx.begin();
}


void loop()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == LOW)
  {
    warning();
  }

  else if (buttonState2 == LOW)
  {
    pursuit();
  }
  
  else
  {
    //Do Nothing!
  }
}

/*
 * Function that plays a short warning sound and flashes police lights
 */
void warning()
{
  flashLEDsOnce();
  sfx.playFileNumber(1);
  flashLEDsShort();
}

/*
 * Function that plays a pursuit sound and flashes police lights.
 */
void pursuit()
{
  flashLEDsOnce();
  sfx.playFileNumber(2);
  flashLEDsLong();
}

/*
 * quick burst of police lights
 */
void flashLEDsOnce()
{
  for (int i = 0; i <= 4; i++) {
    digitalWrite(Red, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                       // wait for a second
    digitalWrite(Red, LOW);    // turn the LED off by making the voltage LOW
    delay(50);                       // wait for a second
  }
  for (int i = 0; i <= 5; i++) {
    digitalWrite(Blue, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                       // wait for a second
    digitalWrite(Blue, LOW);    // turn the LED off by making the voltage LOW
    delay(50);                       // wait for a second
  }
}

/*
 * Short sequence of police lights
 */
void flashLEDsShort()
{
  for (int j = 0; j <= 2; j++) {
    for (int i = 0; i <= 4; i++) {
      digitalWrite(Red, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);                       // wait for a second
      digitalWrite(Red, LOW);    // turn the LED off by making the voltage LOW
      delay(50);                       // wait for a second
    }
    for (int i = 0; i <= 5; i++) {
      digitalWrite(Blue, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);                       // wait for a second
      digitalWrite(Blue, LOW);    // turn the LED off by making the voltage LOW
      delay(50);                       // wait for a second
    }
  }
}

/*
 * Long sequence of police lights.
 */
void flashLEDsLong()
{
  for (int j = 0; j <= 26; j++) {
    for (int i = 0; i <= 4; i++) {
      digitalWrite(Red, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);                       // wait for a second
      digitalWrite(Red, LOW);    // turn the LED off by making the voltage LOW
      delay(50);                       // wait for a second
    }
    for (int i = 0; i <= 5; i++) {
      digitalWrite(Blue, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);                       // wait for a second
      digitalWrite(Blue, LOW);    // turn the LED off by making the voltage LOW
      delay(50);                       // wait for a second
    }
  }
}
