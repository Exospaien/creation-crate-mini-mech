#ifndef SOLENOID_H
#define SOLENOID_H

#include <Arduino.h>

using namespace std;

class Solenoid {
      
   public:
      Solenoid(int pin);  
      void begin();
      void extend();
      void retract();
      void loop();
      void toggle();
 
   private:
      static int solenoidActive;
      static int pumpPin;
      int pin;
      bool extending;
      
};

#endif
