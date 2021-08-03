#include "solenoid.h"
//pump 400ma
//sol 130ma

int Solenoid::solenoidActive = 0;
int Solenoid::pumpPin = 3;

Solenoid left_outer_knee(4);
Solenoid left_outer_hip(5);
Solenoid left_inner_knee(6);
Solenoid left_inner_hip(7);
Solenoid right_inner_knee(8);
Solenoid right_inner_hip(9);
Solenoid right_outer_knee(10);
Solenoid right_outer_hip(11);

int incomingByte = 0;

void setup()
{

  Serial.begin(9600);
  left_outer_knee.begin();
  left_outer_hip.begin();
  left_inner_knee.begin();
  left_inner_hip.begin();
  right_inner_knee.begin();
  right_inner_hip.begin();
  right_outer_knee.begin();
  right_outer_hip.begin();
}

void solenoidLoops()
{
  left_outer_knee.loop();
  left_outer_hip.loop();
  left_inner_knee.loop();
  left_inner_hip.loop();
  right_inner_knee.loop();
  right_inner_hip.loop();
  right_outer_knee.loop();
  right_outer_hip.loop();

}

void loop()
{
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if(incomingByte == 97){
      left_outer_knee.toggle();
    }
    
    if(incomingByte == 115){
      left_outer_hip.toggle();
    }

    if(incomingByte == 100){
      left_inner_knee.toggle();
    }
    
    if(incomingByte == 102){
      left_inner_hip.toggle();
    }
 
    if(incomingByte == 103){
      right_inner_knee.toggle();
    }
    
    if(incomingByte == 104){
      right_inner_hip.toggle();
    }
 
    if(incomingByte == 106){
      right_outer_knee.toggle();
    }
    
    if(incomingByte == 107){
      right_outer_hip.toggle();
    }
    solenoidLoops();
  }
}
