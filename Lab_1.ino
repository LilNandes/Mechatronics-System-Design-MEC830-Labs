#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

int trigPin=5;
int echoPin=3;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  
 
  
}

void loop()
{
  
}
