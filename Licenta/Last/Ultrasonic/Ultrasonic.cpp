#include <Arduino.h>
#include <Ultrasonic.h>

Ultrasonic::Ultrasonic(int trigPin, int echoPin) {
  _trigPin = trigPin;
  _echoPin = echoPin;

  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

int Ultrasonic::read() {

  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

int duration = pulseIn(_echoPin, HIGH);
return duration / 2.0 * 0.0343;
}
