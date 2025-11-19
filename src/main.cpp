#include "Arduino.h"
#include "ESP32_Servo.h"
#include "PS4Controller.h"

const int motorPin[4] = {34, 35, 32, 33};
const int Servopin = 15;

Servo myServo;

void setup()
{
  for(int i = 0; i < 4; i++)
  {
    ledcSetup(i + 4, 12800, 8);
    ledcAttachPin(motorPin[i], i + 4);
  }

  PS4.begin("01:02:03:04:05:06");
  myServo.attach(Servopin);
}

void setmotor(int speed)
{
  if(speed > 50)
  {
    ledcWrite(4, speed);
    ledcWrite(5, 0);
    ledcWrite(6, speed);
    ledcWrite(7, 0);
  }
  else if(abs(speed) > 50)
  {
    ledcWrite(4, 0);
    ledcWrite(5, abs(speed));
    ledcWrite(6, 0);
    ledcWrite(7, abs(speed));
  }
  else
  {
    for(int i = 4; i < 8; i++)
    {
      ledcWrite(i, 0);
    }
  }
}

void Handleservo(int angle)
{
  int servoangle = (int)(angle / 10) + 90;
  myServo.write(servoangle);
}

void loop()
{
  ledcWrite(4, 0);
  ledcWrite(5, 200);
  ledcWrite(6, 0);
  ledcWrite(7, 200);

  myServo.write(90);
  delay(1000);
  myServo.write(0);
  delay(1000);
}