#include "solenoid.h"

// class variables... so shared amoungst the different instances of the class. 
// Thus every instance of the class has access to solenoidActive and pumpPin
int Solenoid::solenoidActive = 0;
int Solenoid::pumpPin = 3;

elapsedSeconds timer;

Solenoid::Solenoid(int pin) : pin(pin), extending(false)
{
}

void Solenoid::begin()
{
   pinMode(pumpPin, OUTPUT); //sets the pin to output 
   pinMode(pin, OUTPUT); //sets the pin to output 
}

void Solenoid::extend()
{
   if(!extending){
      extending = true;
      solenoidActive++;  //We keep a tally of the number of solenoids active so we know when to keep the pump on
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
   if(solenoidActive > 0){ // If any solenoid is active we want the pump to be active
      digitalWrite(pumpPin, HIGH);
   }else{
      digitalWrite(pumpPin, LOW);
   }

   // We have a timout so it remains active for a bit. Needed to maintain pressure
   if((solenoidActive > 0 || timer < TIMEOUT_PERIOD) && !extending){
      digitalWrite(pin, HIGH);
   }else{
      digitalWrite(pin, LOW);
   }

}
