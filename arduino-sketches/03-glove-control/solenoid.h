#ifndef SOLENOID_H
#define SOLENOID_H

#include <Arduino.h>
#include <elapsedMillis.h>

#define TIMEOUT_PERIOD 30  // Set to 30 seconds
      
using namespace std;

class Solenoid {
      
   public:
      Solenoid(int pin);  
      void begin();
      void extend();
      void retract();
      void loop();
 
   private:
      static int solenoidActive;
      static int pumpPin;
      int pin;
      bool extending;
      
};

#endif
