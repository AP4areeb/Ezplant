#include <arduino.h>
#include <servo.h>

#define sensorIn A0
#define servoOut 3
#define pumpRelay 4

Servo spread; //idk what to name it

void setup()
{
  spread.attach(servoOut);
  Pinmode(pumpRelay,OUTPUT);
  Pinmode(sensorIn,INPUT);
  int waterTimeMS = 75000;
}
void loop()
{
  
}//:) To Be Finished
