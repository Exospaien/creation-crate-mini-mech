#include "solenoid.h"
      

void Solenoid::setupPump(int pin)
{
   solenoidActive = 0;
   pumpPin = pin;
   pinMode(pin, OUTPUT);
}

Solenoid::Solenoid(int pin) : pin(pin), extending(false)
{
}

void Solenoid::begin()
{
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

void Solenoid::toggle(){
  if(extending){
    retract();
  }else{
    extend();
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
