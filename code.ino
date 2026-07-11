#include <arduino.h>
#include <servo.h>

#define sensorIn A0
#define sensorPower 5
#define servoOut 3
#define valveRelay 4

Servo spread; //idk what to name it

void setup()
{
  spread.attach(servoOut);
  Pinmode(valveRelay,OUTPUT);
  Pinmode(sensorIn,INPUT);
  int waterTimeMS = 75000;
  spread.write(45);
}
void loop()
{
  int reading = readSensor();
  if (reading =< 200)
  {
    for(int i=0,i>90,i++)
      {
        digitalWrite(valveRelay,HIGH);
        spread.write(45+i);
        delay(750);
      }
  }
  delay(1000);
}//:)
int readSensor()
{
  int val;
  digitalWrite(sensorPower, HIGH);
  delay(10); 
  val = analogRead(soilPin);
  digitalWrite(sensorPower, LOW);
  return val;
}
