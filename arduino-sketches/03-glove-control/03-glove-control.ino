#include <PCF8574.h>

#include "solenoid.h"
#include "glove.h"

//PCF8574 pcf(0x20);

Solenoid s_left_outer_knee(4);
Solenoid s_left_outer_hip(5);
Solenoid s_left_inner_knee(6);
Solenoid s_left_inner_hip(7);
Solenoid s_right_inner_knee(8);
Solenoid s_right_inner_hip(9);
Solenoid s_right_outer_knee(10);
Solenoid s_right_outer_hip(11);

Glove g_left_outer_knee(0);
Glove g_left_outer_hip(1);
Glove g_left_inner_knee(2);
Glove g_left_inner_hip(3);
Glove g_right_inner_knee(4);
Glove g_right_inner_hip(5);
Glove g_right_outer_knee(6);
Glove g_right_outer_hip(7);

int incomingByte = 0;

void setup()
{
  Serial.begin(9600);
  //pcf.begin();

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
  g_right_outer_knee.loop();
  g_right_outer_hip.loop();
}

void toggle(){
  byte inputStates = 0;
//  byte inputStates = pcf.readButton8();

  if(g_left_outer_knee.isFlexed() || bitRead(inputStates, 0))
    s_left_outer_knee.extend();
  else
    s_left_outer_knee.retract();

  if(g_left_outer_hip.isFlexed() || bitRead(inputStates, 1))
    s_left_outer_hip.extend();
  else
    s_left_outer_hip.retract();

  if(g_left_inner_knee.isFlexed() || bitRead(inputStates, 2))
    s_left_inner_knee.extend();
  else
    s_left_inner_knee.retract();

  if(g_left_inner_hip.isFlexed() || bitRead(inputStates, 3))
    s_left_inner_hip.extend();
  else
    s_left_inner_hip.retract();

  if(g_right_inner_knee.isFlexed() || bitRead(inputStates, 4))
    s_right_inner_knee.extend();
  else
    s_right_inner_knee.retract();

  if(g_right_inner_hip.isFlexed() || bitRead(inputStates, 5))
    s_right_inner_hip.extend();
  else
    s_right_inner_hip.retract();

  if(g_right_outer_knee.isFlexed() || bitRead(inputStates, 6))
    s_right_outer_knee.extend();
  else
    s_right_outer_knee.retract();

  if(g_right_outer_hip.isFlexed() || bitRead(inputStates, 7))
    s_right_outer_hip.extend();
  else
    s_right_outer_hip.retract();

}


void loop()
{
  solenoidLoops();
  gloveLoops();
  toggle();
  delay(250);
  Serial.println();
  Serial.println();
}
