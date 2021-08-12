#include <PCF8574.h>
#include <Wire.h>

#include "solenoid.h"

PCF8574 pcf(0x20);

Solenoid s_left_outer_knee(4);
Solenoid s_left_outer_hip(5);
Solenoid s_left_inner_knee(6);
Solenoid s_left_inner_hip(7);
Solenoid s_right_inner_knee(8);
Solenoid s_right_inner_hip(9);
Solenoid s_right_outer_knee(10);
Solenoid s_right_outer_hip(11);

void setup()
{
  pcf.begin();
  s_left_outer_knee.begin();
  s_left_outer_hip.begin();
  s_left_inner_knee.begin();
  s_left_inner_hip.begin();
  s_right_inner_knee.begin();
  s_right_inner_hip.begin();
  s_right_outer_knee.begin();
  s_right_outer_hip.begin();
}

void solenoidLoops()
{
  s_left_outer_knee.loop();
  s_left_outer_hip.loop();
  s_left_inner_knee.loop();
  s_left_inner_hip.loop();
  s_right_inner_knee.loop();
  s_right_inner_hip.loop();
  s_right_outer_knee.loop();
  s_right_outer_hip.loop();
}


void toggleFromButtons(){
  byte inputStates = pcf.readButton8();

  if(bitRead(inputStates, 0))
    s_left_outer_knee.extend();
  else
    s_left_outer_knee.retract();

  if(bitRead(inputStates, 1))
    s_left_outer_hip.extend();
  else
    s_left_outer_hip.retract();

  if(bitRead(inputStates, 2))
    s_left_inner_knee.extend();
  else
    s_left_inner_knee.retract();

  if(bitRead(inputStates, 3))
    s_left_inner_hip.extend();
  else
    s_left_inner_hip.retract();

  if(bitRead(inputStates, 4))
    s_right_inner_knee.extend();
  else
    s_right_inner_knee.retract();

  if(bitRead(inputStates, 5))
    s_right_inner_hip.extend();
  else
    s_right_inner_hip.retract();

  if(bitRead(inputStates, 6))
    s_right_outer_knee.extend();
  else
    s_right_outer_knee.retract();

  if(bitRead(inputStates, 7))
    s_right_outer_hip.extend();
  else
    s_right_outer_hip.retract();

}

void loop()
{
  toggleFromButtons();
  solenoidLoops();
  delay(50);
}

