//www.elegoo.com
//2018.12.19
#include <Servo.h>

Servo myservo;

volatile int state = 0;
//volatile int state2 = 0;
int a=90;

void setup(){

  myservo.attach(9);//connect pin 9 with the control line(the middle line of Servo) 
  myservo.write(90);// move servos to center position -> 90°
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), CCW, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), CW, FALLING);
} 
void loop(){
  
  if (state == 1)
  {
    myservo.write(a);// move servos to center position -> 60°
  delay(1000);
  state=0;
  }

//  delay(1000);
//  myservo.write(60);// move servos to center position -> 60°
//  delay(1000);
//  myservo.write(90);// move servos to center position -> 90°
//  delay(1000);
//  myservo.write(150);// move servos to center position -> 120°
//  delay(1000);
}

void CCW()
{
  state=1;
  a=a+45;
}

void CW()
{
  state=1;
  a=a-45;
}
