#include <Arduino.h>

using namespace std;

class Glove {

   public:
      static int muxPin;
      
      static void setupMux(int pin);

      Glove(int inputNumber);
      void loop();

      int adcValue;

      bool isFlexed();

   private:
      int pin;

};
