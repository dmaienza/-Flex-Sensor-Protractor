#include <Servo.h>
#include <Time.h>
#define UPDATE 100

Servo servo1;
const int flexPin = A0;
unsigned long timeStamp = 0;
unsigned long readTime = 0;
int i;
int servoPosition;
float flexPositionTotal = 0.0;
float flexAverage;

void setup ()
{
  Serial.begin(9600);
  servo1.attach(9);
}

void loop ()
{
  timeStamp = millis();
 
  if ((timeStamp - readTime) >= UPDATE) {
  Serial.print("Time(s): ");
  Serial.print(timeStamp / 1000.0);

  flexAverage = flexPositionTotal / i;
  servoPosition = map(flexAverage, 360, 920, 90, 0);
  servoPosition = constrain(servoPosition, 0, 90);
  servo1.write(servoPosition);

  Serial.print("  sensor: ");
  Serial.print(flexAverage);
  Serial.print(" servo: ");
  Serial.println(servoPosition);

  readTime = timeStamp;
  i = 0;
  flexPositionTotal = 0.0;
  
  } else {
  flexPositionTotal += analogRead(flexPin);
  i += 1;
  // Serial.print(" i: ");
  // Serial.print(i);
  }
}
