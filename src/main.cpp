#include <Arduino.h>
#include "ESP32_Servo.h"

const int motorPin[4] = {34, 35, 32, 33};
const int Servopin = 15;

Servo myServo;

void setup() {
  for(int i = 4; i < 8; i++)
  {
    ledcSetup(i, 12800, 8);
    ledcAttachPin(motorPin[i], i);
  }

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
  // myServo.write(angle / 10 + 90);
}

void loop() {
  // for(int i = 0; i < 4; i++)
  // {
  //   ledcWrite(i, 200);
  // }
  ledcWrite(4, 0);
  ledcWrite(5, 200);
  ledcWrite(6, 0);
  ledcWrite(7, 200);
}