#include <PCF8574.h>
#include <Wire.h>

#include "solenoid.h"

#define LEFT_OUTER_KNEE_S     5
#define LEFT_OUTER_HIP_S      4
#define LEFT_INNER_KNEE_S     6
#define LEFT_INNER_HIP_S      7
#define RIGHT_INNER_KNEE_S    8
#define RIGHT_INNER_HIP_S     9
#define RIGHT_OUTER_KNEE_S    10
#define RIGHT_OUTER_HIP_S     11

#define LEFT_OUTER_KNEE_B     3
#define LEFT_OUTER_HIP_B      4
#define LEFT_INNER_KNEE_B     5
#define LEFT_INNER_HIP_B      2
#define RIGHT_INNER_KNEE_B    6
#define RIGHT_INNER_HIP_B     1
#define RIGHT_OUTER_KNEE_B    7
#define RIGHT_OUTER_HIP_B     0

PCF8574 pcf(0x20);

Solenoid s_left_outer_knee(LEFT_OUTER_KNEE_S);
Solenoid s_left_outer_hip(LEFT_OUTER_HIP_S);
Solenoid s_left_inner_knee(LEFT_INNER_KNEE_S);
Solenoid s_left_inner_hip(LEFT_INNER_HIP_S);
Solenoid s_right_inner_knee(RIGHT_INNER_KNEE_S);
Solenoid s_right_inner_hip(RIGHT_INNER_HIP_S);
Solenoid s_right_outer_knee(RIGHT_OUTER_KNEE_S);
Solenoid s_right_outer_hip(RIGHT_OUTER_HIP_S);

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

  if(!bitRead(inputStates, LEFT_OUTER_KNEE_B))
    s_left_outer_knee.extend();
  else
    s_left_outer_knee.retract();

   if(!bitRead(inputStates, LEFT_OUTER_HIP_B))
     s_left_outer_hip.extend();
   else
     s_left_outer_hip.retract();

   if(!bitRead(inputStates, LEFT_INNER_KNEE_B))
     s_left_inner_knee.extend();
   else
     s_left_inner_knee.retract();

   if(!bitRead(inputStates, LEFT_INNER_HIP_B))
     s_left_inner_hip.extend();
   else
     s_left_inner_hip.retract();

   if(!bitRead(inputStates, RIGHT_INNER_KNEE_B))
     s_right_inner_knee.extend();
   else
     s_right_inner_knee.retract();

   if(!bitRead(inputStates, RIGHT_INNER_HIP_B))
     s_right_inner_hip.extend();
   else
     s_right_inner_hip.retract();

   if(!bitRead(inputStates, RIGHT_OUTER_KNEE_B))
     s_right_outer_knee.extend();
   else
     s_right_outer_knee.retract();

   if(!bitRead(inputStates, RIGHT_OUTER_HIP_B))
     s_right_outer_hip.extend();
   else
     s_right_outer_hip.retract();

}

void loop()
{
  toggleFromButtons();
  solenoidLoops();
  delay(100);
}
