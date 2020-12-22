//www.elegoo.com
//2016.12.08
#include <LiquidCrystal.h>
#include "SR04.h"

#define TRIG_PIN 5
#define ECHO_PIN 3

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
float a, duration, cm;

void setup() {
   Serial.begin(9600);//Initialization of Serial Port
   delay(1000);
     // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Distance (cm):");

    pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
}

void loop() 
{
   digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;
   lcd.setCursor(0, 1);
   a=sr04.Distance();
   //lcd.print(a);
   lcd.print(cm);
   Serial.print(a);
   //lcd.print("cm");//The difference between "Serial.print" and "Serial.println" 
   lcd.print("       ");                     //is that "Serial.println" can change lines.
   delay(500);
}
