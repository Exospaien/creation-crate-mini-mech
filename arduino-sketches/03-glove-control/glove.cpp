#include "glove.h"


const int muxPinA = 12;
const int muxPinB = 13;

void Glove::begin()
{
   pinMode(muxPinA, OUTPUT);
   pinMode(muxPinB, OUTPUT);
   digitalWrite(muxPinA, LOW);
   digitalWrite(muxPinB, LOW);
}

Glove::Glove(int inputNumber) : inputNumber(inputNumber), adcValue(0)
{
}


void Glove::loop()
{
  adcValue = 0;
   switch(inputNumber){
      case 0:
      case 1:
         digitalWrite(muxPinA, LOW);
         digitalWrite(muxPinB, LOW);
      break;

      case 2:
      case 3:
         digitalWrite(muxPinA, LOW);
         digitalWrite(muxPinB, HIGH);
      break;

      case 4:
      case 5:
         digitalWrite(muxPinA, HIGH);
         digitalWrite(muxPinB, LOW);
      break;

      case 6:
      case 7:
         digitalWrite(muxPinA, HIGH);
         digitalWrite(muxPinB, HIGH);
      break;
   }

   delay(10);

   if(inputNumber % 2 == 0)
      adcValue = analogRead(A0);
   else
      adcValue = analogRead(A1);

   Serial.print("input: ");
   Serial.print(inputNumber);
   Serial.print(" , ");
   Serial.println(adcValue);

}

bool Glove::isFlexed(unsigned int threshold)
{
   if(adcValue > threshold)
      return false;

   return true;
}
