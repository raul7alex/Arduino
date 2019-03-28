#include "Motorscontrol.h"
#include "Arduino.h"

Motorscontrol::Motorscontrol(int motorPin, int in1, int in2, int speed)
{
  _motorPin=motorPin;
  _in1=in1;
  _in2=in2;
  _speed=speed;

  pinMode(_motorPin, OUTPUT);
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
}

void Motorscontrol::stop(){
   analogWrite(_motorPin,0);
   digitalWrite(_in1, LOW);
   digitalWrite(_in2, LOW);
}

void Motorscontrol::forward(int _speed)
{
   analogWrite(_motorPin,_speed);
   digitalWrite(_in1, LOW);
   digitalWrite(_in2, HIGH);
}

void Motorscontrol::backward(int _speed)
{
   analogWrite(_motorPin,_speed);
   digitalWrite(_in1, HIGH);
   digitalWrite(_in2, LOW);
}
