#include "glove.h"
      
void Glove::setupMux(int pin)
{
   muxPin = pin;
   pinMode(pin, OUTPUT);
   digitalWrite(pin, LOW);
}


Glove::Glove(int inputNumber) : inputNumber(inputNumber), adcValue(0)
{
}

void Glove::loop()
{
   switch(inputNumber){
      case 0:
      case 1:
      case 2:
         digitalWrite(muxPin, LOW);
         delay(10);
      break;

      case 3:
      case 4:
      case 5:
         digitalWrite(muxPin, HIGH);
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

}

bool Glove::isFlexed()
{
   if(adcValue < 500){
      return false;
   }

   return true;
}
