#ifndef GLOVE_H
#define GLOVE_H

#include <Arduino.h>

using namespace std;

class Glove {

   public:
      static void begin();
      Glove(int inputNumber);
      void loop();
      bool isFlexed();

   private:
      static int muxPin;
      int adcValue;
      int inputNumber;

};

#endif
