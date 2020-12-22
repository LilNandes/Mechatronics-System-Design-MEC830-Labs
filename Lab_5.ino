/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/
#include <Servo.h>
#include <PID_v1.h>
#include <LiquidCrystal.h>
#include "SR04.h"

#define TRIG_PIN 6
#define ECHO_PIN 5

#define PIN_INPUT 5
#define PIN_OUTPUT 

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=0, Ki=10, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

Servo myservo;
volatile int state = 0;
int pb1=2;
int pb2=3;
int a=0;
float duration, d, Error;

void setup()
{
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  myservo.attach(9);//connect pin 9 with the control line(the middle line of Servo) 
  myservo.write(0);// move servos to center position -> 90°
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pb1), CCW, FALLING);
  attachInterrupt(digitalPinToInterrupt(pb2), CW, FALLING);
  //initialize the variables we're linked to
  Setpoint = 6.00;
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
//   if (state == 1)
//  {
//  myservo.write(a);// move servos to center position -> 60°
//  delay(50);
//  state=0;
//  }
   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(5);
   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);
   pinMode(ECHO_PIN, INPUT);
   duration = pulseIn(ECHO_PIN, HIGH);
   d = (duration/2) / 29.1;
  Error=Setpoint-d;
  Input = d;
  myPID.Compute();
  Serial.print(Input);
  //Serial.print(Error);
  Serial.print(",");
  a=map((Output),0,255,0,90);
  Serial.println(Setpoint);
  myservo.write(a);
  delay(0);
  
  
}

void CCW()
{
  state=1;
  Setpoint=Setpoint+0.5;
}

void CW()
{
  state=1;
  Setpoint=Setpoint-0.5;
}
