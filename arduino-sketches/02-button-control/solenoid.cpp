#include "solenoid.h"

int Solenoid::solenoidActive = 0;
int Solenoid::pumpPin = 3;

elapsedSeconds timer;

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
   timer = 0;
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
   }else{
      digitalWrite(pumpPin, LOW);
   }

   if((solenoidActive > 0 || timer < TIMEOUT_PERIOD) && !extending){
      digitalWrite(pin, HIGH);
   }else{
      digitalWrite(pin, LOW);
   }

}
