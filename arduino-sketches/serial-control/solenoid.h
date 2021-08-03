#include <Arduino.h>

using namespace std;

class Solenoid {

   public:
      static int solenoidActive;
      static int pumpPin;
      
      Solenoid(int pin);
      void begin();
      void extend();
      void retract();
      void loop();
      void toggle();

   private:
      int pin;
      bool extending;

};
