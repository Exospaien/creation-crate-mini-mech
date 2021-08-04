#include "solenoid.h"
#include "glove.h"


Solenoid::setupPump(3);
Solenoid s_left_outer_knee(4);
Solenoid s_left_outer_hip(5);
Solenoid s_left_inner_knee(6);
Solenoid s_left_inner_hip(7);
Solenoid s_right_inner_knee(8);
Solenoid s_right_inner_hip(9);
Solenoid s_right_outer_knee(10);
Solenoid s_right_outer_hip(11);

Glove::setupMux(12);
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
  sg_right_outer_hip.loop();
}

void toggleFromSerial()
{
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    switch(incomingByte){

      case 97: //a
        s_left_outer_knee.toggle();
      break;

      case 115://s
        s_left_outer_hip.toggle();
      break;

      case 100: //d
        s_left_inner_knee.toggle();
      break;

      case 102: //f
        s_left_inner_hip.toggle();
      break;

      case 103: //g
        s_right_inner_knee.toggle();
      break;

      case 104: //h
        s_right_inner_hip.toggle();
      break;

      case 106: //j
        s_right_outer_knee.toggle();
      break;

      case 107: //k
       s_right_outer_hip.toggle();
      break;
    }
  }
}


void loop()
{
  toggleFromSerial();
  solenoidLoops();
  gloveLoops();
  delay(1);

}
