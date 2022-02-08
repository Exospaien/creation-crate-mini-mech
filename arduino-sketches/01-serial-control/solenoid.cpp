#include "solenoid.h"

int Solenoid::solenoidActive = 0;
int Solenoid::pumpPin = 3;

Solenoid::Solenoid(int pin) : pin(pin), extending(false)
{
}

void Solenoid::begin()
{
   pinMode(pumpPin, OUTPUT);
   pinMode(pin, OUTPUT);
}

void Solenoid::extend()
{
   if(!extending){
      extending = true;
      solenoidActive++;
   }
}

void Solenoid::retract()
{
   if(extending){
      extending = false;
      solenoidActive--;
   }
}

void Solenoid::loop()
{
   if(solenoidActive > 0){
      digitalWrite(pumpPin, HIGH);
      
      if(extending){
         digitalWrite(pin, LOW);
      }else{
         digitalWrite(pin, HIGH);
      }

   }else{
      digitalWrite(pumpPin, LOW);
      digitalWrite(pin, LOW);
   }

}
