#ifndef Motorscontrol_h
#define Motorscontrol_h

#include "Arduino.h"

class Motorscontrol
{
  public:
    Motorscontrol(int motorPin, int in1, int in2, int speed);
    void forward(int speed);
    void backward(int speed);
    void stop();

   private:
    int _motorPin;
    int _in1;
    int _in2;
    int _speed;
};

#endif
