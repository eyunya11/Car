#include <Arduino.h>
#include "ESP32_Servo.h"

const int motorPin[4] = {34, 35, 32, 33};
const int Servopin = 15;

Servo myServo;

void setup() {
  for(int i = 0; i < 4; i++)
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
    ledcWrite(0, speed);
    ledcWrite(1, 0);
    ledcWrite(2, speed);
    ledcWrite(3, 0);
  }
  else if(abs(speed) > 50)
  {
    ledcWrite(0, 0);
    ledcWrite(1, abs(speed));
    ledcWrite(2, 0);
    ledcWrite(3, abs(speed));
  }
  else
  {
    for(int i = 0; i < 4; i++)
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
  ledcWrite(0, 0);
  ledcWrite(1, 200);
  ledcWrite(2, 0);
  ledcWrite(3, 200);
}