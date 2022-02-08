#include "glove.h"

// Refer to this datasheet for information on how the mux works https://www.ti.com/lit/ds/symlink/cd4052b.pdf
const int muxPinA = 12;
const int muxPinB = 13;

void Glove::begin()
{
   pinMode(muxPinA, OUTPUT); // Sets the mux pin A to output.
   pinMode(muxPinB, OUTPUT); // Sets the mux pin B to output.
   digitalWrite(muxPinA, LOW); // Sets the mux pin A to low (set the pin to ground)
   digitalWrite(muxPinB, LOW); // Sets the mux pin B to low (set the pin to ground)
}

Glove::Glove(int inputNumber) : inputNumber(inputNumber), adcValue(0)  // Glove class constructor
{
}


void Glove::loop()
{
  adcValue = 0;
   switch(inputNumber){ // This switch statement sets the mux so we can read from a particular finger. 
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

   if(inputNumber % 2 == 0) // Our mux is a 8 input to 2 output. So we read the even inputs with one of the Arduino's ADC's and odd with the other
      adcValue = analogRead(A0);
   else
      adcValue = analogRead(A1);

   // Prints out input value to the serial port for help with debugging and setting the threshold
   Serial.print("input: ");
   Serial.print(inputNumber);
   Serial.print(" , ");
   Serial.println(adcValue);

}

// We need to read with a particular threashold as each finger doesn't have the same dimensions and what "flexed" is will vary. 
// A calibration needs to be done for each finger to find what the flexed value limit is
bool Glove::isFlexed(unsigned int threshold)
{
   if(adcValue > threshold)
      return false;

   return true;
}
