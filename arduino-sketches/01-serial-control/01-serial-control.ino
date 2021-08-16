#include "solenoid.h"

#define LEFT_OUTER_KNEE_S     5
#define LEFT_OUTER_HIP_S      4
#define LEFT_INNER_KNEE_S     6
#define LEFT_INNER_HIP_S      7
#define RIGHT_INNER_KNEE_S    8
#define RIGHT_INNER_HIP_S     9
#define RIGHT_OUTER_KNEE_S    10
#define RIGHT_OUTER_HIP_S     11

Solenoid s_left_outer_knee(LEFT_OUTER_KNEE_S);
Solenoid s_left_outer_hip(LEFT_OUTER_HIP_S);
Solenoid s_left_inner_knee(LEFT_INNER_KNEE_S);
Solenoid s_left_inner_hip(LEFT_INNER_HIP_S);
Solenoid s_right_inner_knee(RIGHT_INNER_KNEE_S);
Solenoid s_right_inner_hip(RIGHT_INNER_HIP_S);
Solenoid s_right_outer_knee(RIGHT_OUTER_KNEE_S);
Solenoid s_right_outer_hip(RIGHT_OUTER_HIP_S);

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
  delay(100);
}
