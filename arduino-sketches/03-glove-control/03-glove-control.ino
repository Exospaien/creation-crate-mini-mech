#include <PCF8574.h> // imports the PCF8574 library See https://github.com/RobTillaart/PCF8574

#include "solenoid.h" // imports the header files for the solenoid and gloves
#include "glove.h"

#define LEFT_OUTER_KNEE_S     5
#define LEFT_OUTER_HIP_S      4
#define LEFT_INNER_KNEE_S     7
#define LEFT_INNER_HIP_S      6
#define RIGHT_INNER_KNEE_S    9
#define RIGHT_INNER_HIP_S     8
#define RIGHT_OUTER_KNEE_S    11
#define RIGHT_OUTER_HIP_S     10

// Each of these corresponds to one of the bits within the byte read by the PCF8574 chip. Each bit represents the state (pressed or not) of a button
#define LEFT_OUTER_KNEE_B     0
#define LEFT_OUTER_HIP_B      1
#define LEFT_INNER_KNEE_B     2
#define LEFT_INNER_HIP_B      3
#define RIGHT_INNER_KNEE_B    4
#define RIGHT_INNER_HIP_B     5
#define RIGHT_OUTER_KNEE_B    6
#define RIGHT_OUTER_HIP_B     7


// See https://github.com/RobTillaart/PCF8574 for documentation on this library
PCF8574 pcf(0x20); // it will always be 0x20 as it's the default address for the chip in our application

// Place to store the incoming byte from the above pcf
int incomingByte = 0;

Solenoid s_left_outer_knee(LEFT_OUTER_KNEE_S);
Solenoid s_left_outer_hip(LEFT_OUTER_HIP_S);
Solenoid s_left_inner_knee(LEFT_INNER_KNEE_S);
Solenoid s_left_inner_hip(LEFT_INNER_HIP_S);
Solenoid s_right_inner_knee(RIGHT_INNER_KNEE_S);
Solenoid s_right_inner_hip(RIGHT_INNER_HIP_S);
Solenoid s_right_outer_knee(RIGHT_OUTER_KNEE_S);
Solenoid s_right_outer_hip(RIGHT_OUTER_HIP_S);

Glove g_left_outer_knee(3);
Glove g_left_outer_hip(4);
Glove g_left_inner_knee(0);
Glove g_left_inner_hip(5);
Glove g_right_inner_knee(1);
Glove g_right_inner_hip(6);
Glove g_right_outer_knee(7);
Glove g_right_outer_hip(2);


void setup() // runs once when the microcontroller starts to setup various things needed
{
  Serial.begin(9600); // Start the serial port running at 9600 baud

  // call the setup functions for the pcf, solenoid, and glove classes
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

void solenoidLoops() // solenoid loop: calls the loop functions in each instance of the solenoid class
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

void gloveLoops() // glove loop: calls the loop functions in each instance of the glove class
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

  // See https://github.com/RobTillaart/PCF8574 for documentation on this library
  byte inputStates = pcf.readButton8(); // Will read each input as a single byte

  if(g_left_outer_knee.isFlexed(240) || !bitRead(inputStates, LEFT_OUTER_KNEE_B)) // bitRead Isolates a bit from the byte. See https://www.arduino.cc/reference/en/language/functions/bits-and-bytes/bitread/
    s_left_outer_knee.retract(); //knees retract when the glove is flex, hips do the opposite
  else
    s_left_outer_knee.extend();

   if(g_left_outer_hip.isFlexed(200) || !bitRead(inputStates, LEFT_OUTER_HIP_B)) // isFlexed and bitRead are OR'ed ( || ) so either a button press or a flex of the glove will extend
     s_left_outer_hip.extend();
   else
     s_left_outer_hip.retract();

  if(g_left_inner_knee.isFlexed(240) || !bitRead(inputStates, LEFT_INNER_KNEE_B))
     s_left_inner_knee.retract(); 
   else
     s_left_inner_knee.extend();

   if(g_left_inner_hip.isFlexed(310) || !bitRead(inputStates, LEFT_INNER_HIP_B))
     s_left_inner_hip.extend();
   else
     s_left_inner_hip.retract();

   if(g_right_inner_knee.isFlexed(200)|| !bitRead(inputStates, RIGHT_INNER_KNEE_B))
     s_right_inner_knee.retract();
   else
     s_right_inner_knee.extend();

   if(g_right_inner_hip.isFlexed(250)|| !bitRead(inputStates, RIGHT_INNER_HIP_B))
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

// Loop runs continuously when microcontroller is running  
void loop() 
{
  solenoidLoops();
  gloveLoops();
  toggle();
  delay(100); // We only want to update it every 100ms to prevent it from being too jumpy
}
