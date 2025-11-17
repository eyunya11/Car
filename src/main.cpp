#include <Arduino.h>

int motorPin[4] = {34, 35, 32, 33};

void setup() {
  // for(int i = 0; i < 4; i++)
  // {
  //   ledcSetup(i, 12800, 8);
  //   ledcAttachPin(motorPin[i], i);
  // }

    ledcSetup(0, 12800, 8);
    ledcAttachPin(motorPin[0], 0);
    ledcSetup(1, 12800, 8);
    ledcAttachPin(motorPin[1], 1);
    ledcSetup(2, 12800, 8);
    ledcAttachPin(motorPin[2], 2);
    ledcSetup(3, 12800, 8);
    ledcAttachPin(motorPin[3], 3);
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
  // myServo.write(angle);
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