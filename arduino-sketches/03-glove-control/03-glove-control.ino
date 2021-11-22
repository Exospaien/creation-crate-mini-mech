#include <PCF8574.h>

#include "solenoid.h"
#include "glove.h"

#define LEFT_OUTER_KNEE_S     4
#define LEFT_OUTER_HIP_S      5
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

Glove g_left_outer_knee(1);
Glove g_left_outer_hip(4);
Glove g_left_inner_knee(2);
Glove g_left_inner_hip(5);
Glove g_right_inner_knee(0);
Glove g_right_inner_hip(3);
Glove g_right_outer_knee(7);
Glove g_right_outer_hip(6);

int incomingByte = 0;

void setup()
{
  Serial.begin(9600);
  pcf.begin();
  Glove::begin();

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

void gloveLoops()
{
  g_left_outer_knee.loop();
  g_left_outer_hip.loop();
  g_left_inner_knee.loop();
  g_left_inner_hip.loop();
  g_right_inner_knee.loop();
  g_right_inner_hip.loop();
  g_right_outer_hip.loop();
  g_right_outer_knee.loop();
}

void toggle(){

  byte inputStates = pcf.readButton8();

  if(g_left_outer_knee.isFlexed(225)|| !bitRead(inputStates, LEFT_OUTER_KNEE_B))
    s_left_outer_knee.retract();
  else
    s_left_outer_knee.extend();

   if(g_left_outer_hip.isFlexed(260)|| !bitRead(inputStates, LEFT_OUTER_HIP_B))
     s_left_outer_hip.extend();
   else
     s_left_outer_hip.retract();

  if(g_left_inner_knee.isFlexed(210)|| !bitRead(inputStates, LEFT_INNER_KNEE_B))
     s_left_inner_knee.retract();
   else
     s_left_inner_knee.extend();

   if(g_left_inner_hip.isFlexed(280)|| !bitRead(inputStates, LEFT_INNER_HIP_B))
     s_left_inner_hip.extend();
   else
     s_left_inner_hip.retract();

   if(g_right_inner_knee.isFlexed(200)|| !bitRead(inputStates, RIGHT_INNER_KNEE_B))
     s_right_inner_knee.retract();
   else
     s_right_inner_knee.extend();

   if(g_right_inner_hip.isFlexed(200)|| !bitRead(inputStates, RIGHT_INNER_HIP_B))
     s_right_inner_hip.extend();
   else
     s_right_inner_hip.retract();

  if(g_right_outer_knee.isFlexed(250) || !bitRead(inputStates, RIGHT_OUTER_KNEE_B))
    s_right_outer_knee.retract();
  else
    s_right_outer_knee.extend();

  if(g_right_outer_hip.isFlexed(280) || !bitRead(inputStates, RIGHT_OUTER_HIP_B))
     s_right_outer_hip.extend();
   else
     s_right_outer_hip.retract();

}


void loop()
{
  solenoidLoops();
  gloveLoops();
  toggle();
  delay(50);
}
