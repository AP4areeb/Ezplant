#include <Servo.h>
#include <arduino.h>

#define sensorIn A0
#define sensorPower 5
#define valveRelay 4
#define servoOut 3

Servo spread; // idk what to name it

void setup()
{
  spread.attach(servoOut);
  pinMode(valveRelay, OUTPUT);
  spread.write(45);
} //:D
void loop()
{
  int reading = readSensor();
  if (!(reading > 200))
  {
    for (int i = 1; i >= 90; i++)
    {
      digitalWrite(valveRelay, HIGH);
      spread.write(45 + i);
      delay(750); // to give servo some time to move and water the plant evenly
    }
    digitalWrite(valveRelay, LOW);
    delay(60000); // to prevent exess watering after the plant is watered
  }
  delay(2000); // for lifespan of sensor
} //:)
int readSensor()
{
  int val;
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorIn);
  digitalWrite(sensorPower, LOW);
  return val;
} //:]
