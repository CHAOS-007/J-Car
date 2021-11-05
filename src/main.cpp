#include <Arduino.h>
#include "bt.h"
#include "motion.h"

BT bt;
MOTION motion;

void setup()
{
  // All motor control pins are outputs

  // Front
  pinMode(F_EnL, OUTPUT);
  pinMode(F_EnR, OUTPUT);
  pinMode(F_IL1, OUTPUT);
  pinMode(F_IL2, OUTPUT);
  pinMode(F_IR1, OUTPUT);
  pinMode(F_IR2, OUTPUT);
  // Back
  pinMode(B_EnL, OUTPUT);
  pinMode(B_EnR, OUTPUT);
  pinMode(B_IL1, OUTPUT);
  pinMode(B_IL2, OUTPUT);
  pinMode(B_IR1, OUTPUT);
  pinMode(B_IR2, OUTPUT);

  bt.init();
}

void loop()
{

  while (Serial.available())
  {
    bt.receive();
    
    if (bt.pos1 == 'F')
    {
      if (bt.pos2 == 'L')
      {
        motion.setSpeed(0, bt.speed);
      }
      else if (bt.pos2 == 'R')
      {
        motion.setSpeed(1, bt.speed);
      }
      motion.go();
    }
    else if (bt.pos1 == 'B')
    {
      if (bt.pos2 == 'L')
      {
        motion.setSpeed(2, bt.speed);
      }
      else if (bt.pos2 == 'R')
      {
        motion.setSpeed(3, bt.speed);
      }
      motion.go();
    }
    else if (bt.pos1 == 'S')
    {
      if (bt.pos2 == 'T')
      {
        motion.start();
      }
      else if (bt.pos2 == 'P')
      {
        motion.stop();
      }
    }

    int * checkPoint = motion.checkSpeed();
    Serial.println(*checkPoint);
  }
}