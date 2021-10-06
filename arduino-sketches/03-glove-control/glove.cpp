#include "glove.h"


int Glove::muxPin = 12;

void Glove::begin()
{
   pinMode(muxPin, OUTPUT);
   digitalWrite(muxPin, LOW);
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
      case 2:
         digitalWrite(muxPin, HIGH);
         delay(10);
      break;

      case 3:
      case 4:
      case 5:
         digitalWrite(muxPin, LOW);
         delay(10);
      break;

   }

   switch(inputNumber){
      case 0:
      case 3:
         adcValue = analogRead(A0);
      break;

      case 1:
      case 4:
         adcValue = analogRead(A1);
      break;

      case 2:
      case 5:
         adcValue = analogRead(A2);
      break;

      case 6:
         adcValue = analogRead(A3);
      break;

      case 7:
         adcValue = analogRead(A4);
      break;
   }
//   
//   Serial.print("input: ");
//   Serial.print(inputNumber);
//   Serial.print(" , ");
//   Serial.println(adcValue);

}

bool Glove::isFlexed(unsigned int threshold)
{
   if(adcValue > threshold){
      return false;
   }

   return true;
}
