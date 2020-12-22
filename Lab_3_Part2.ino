//www.elegoo.com
//2016.12.12

#include "Stepper.h"
#define STEPS  32 
#include <Servo.h>
Servo myservo;
volatile int state = 0;
int a=0;

Stepper small_stepper(STEPS, 8, 10, 9, 11);


void setup()
{ 
  small_stepper.setSpeed(500);
//  pinMode(2, INPUT_PULLUP);
//  pinMode(3, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(2), CCW, FALLING);
//  attachInterrupt(digitalPinToInterrupt(3), CW, FALLING);
}

void loop()
{
//  if (state==1)
//  {
   small_stepper.setSpeed(500);
   small_stepper.step(-100);
   delay(500);
}
//   state=0; 
//  }
//
//}
//
//void CCW()
//{
//  state=1;
//  a=256;
//}
//
//void CW()
//{
//  state=1;
//  a=-256;
//}
