#include <Motorscontrol.h>
#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic ultrasonic0(26, 27); //Pini pentru readFront()
Ultrasonic ultrasonic1(24, 25); //Pini pentru readFrontRight()
Ultrasonic ultrasonic2(30, 31); //Pini pentru readRight()
Ultrasonic ultrasonic6(32, 33); //Pini pentru readLeft()
Ultrasonic ultrasonic7(28, 29); //Pini pentru readFrontLeft()

int distanceF;          //Variabile necesare pentru citirea distantei
int distanceL;
int distanceR;
int distanceFL;
int distanceFR;

const int tonePin=11;

Motorscontrol motorA(5, 6, 7, 188);   //Crearea instantei motoarelor
Motorscontrol motorB(10, 9, 8, 188);

Servo steer;   //Crearea instantei servomotorului pentru directie

const int neutral = 50;           //Pozitia servomotorului (in grade)
const int steerRight = -30;
const int steerLeft = 130;

const int frontLimit = 50;    //Limita la care se poate apropia de obiectele detectate(in cm)
const int frontSideLimit = 35;
const int sideLimit = 10;

const int speed = 128; //viteza

void setup() {
  //Serial.begin(9600);             //Pentru debug
  bootsound();                     //Sunet de pornire
  steer.attach(3);                 //Servo atasat la pinul 2
  delay(500);
  motorA.forward(speed);                    //Masina se misca in fata
  motorB.forward(speed);
}

void bootsound() {    //Sunet de pornire
    tone(tonePin, 880, 8.72093023256);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 1479, 8.72093023256);
    delay(9.68992248062);
    delay(38.7596899225);
    tone(tonePin, 783, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 48, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 97, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 440, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 103, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 391, 34.8837209302);
    delay(38.7596899225);
    delay(29.0697674419);
    tone(tonePin, 1975, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(58.1395348837);
    tone(tonePin, 739, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 391, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 880, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 440, 52.3255813953);
    delay(58.1395348837);
    delay(9.68992248062);
    tone(tonePin, 440, 34.8837209302);
    delay(38.7596899225);
    tone(tonePin, 1760, 34.8837209302);
    delay(38.7596899225);
    delay(38.7596899225);
    tone(tonePin, 783, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 783, 78.488372093);
    delay(87.2093023256);
    delay(9.68992248062);
    tone(tonePin, 440, 52.3255813953);
    delay(58.1395348837);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 440, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1479, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 1975, 43.6046511628);
    delay(48.4496124031);
    delay(9.68992248062);
    tone(tonePin, 783, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 880, 52.3255813953);
    delay(58.1395348837);
    tone(tonePin, 739, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 391, 8.72093023256);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 783, 69.7674418605);
    delay(77.519379845);
    delay(19.3798449612);
    delay(106.589147287);
    tone(tonePin, 880, 61.0465116279);
    delay(67.8294573643);
    tone(tonePin, 783, 209.302325581);
    delay(232.558139535);
    tone(tonePin, 587, 17.4418604651);
    delay(19.3798449612);
    delay(145.348837209);
    tone(tonePin, 587, 95.9302325581);
    delay(106.589147287);
}


void readFront() {        //Functie pentru citirea distantei frontale
  distanceF = ultrasonic0.read();
  return (distanceF);
}

void readLeft() {    //Functie pentru citirea distantei din partea stanga
  distanceL = ultrasonic6.read();
  return (distanceL);
}

void readRight() {   //Functie pentru citirea distantei din partea dreapta
  distanceR = ultrasonic2.read();
  return (distanceR);
}

void readFrontLeft() {    //Functie pentru citirea distantei din partea stanga-fata
  distanceFL = ultrasonic7.read();
  return (distanceFL);
}

void readFrontRight() { //Functie pentru citirea distantei din partea dreapta-fata
  distanceFR = ultrasonic1.read();
  return (distanceFR);
}

void rightTurn() {              //Functie care executa un viraj scurt la dreapta pentru evitarea obstacolelor
  steer.write(steerRight);
  motorA.forward(speed);
  motorB.forward(speed);
  delay(50);
  steer.write(neutral);
  //Serial.println("RIGHT TURN");
}

void leftTurn() {               //Functie care executa un viraj scurt la stanga pentru evitarea obstacolelor
  steer.write(steerLeft);
  motorA.forward(speed);
  motorB.forward(speed);
  delay(50);
  steer.write(neutral);
  //Serial.println("LEFT TURN");
}

void longLeftTurn() {           //Functie care executa un viraj de 90 grade la stanga pentru evitarea obstacolelor detectate de senzorul din fata
  steer.write(steerLeft);
  motorA.forward(speed);
  motorB.forward(speed);
  delay(500);
  steer.write(neutral);
  //Serial.println("LONG LEFT");
}

void longRightTurn() {          //Functie care executa un viraj de 90 grade la dreapta pentru evitarea obstacolelor detectate de senzorul din fata
  steer.write(steerRight);
  motorA.forward(speed);
  motorB.forward(speed);
  delay(500);
  steer.write(neutral);
  //Serial.println("LONG RIGHT");
}

void frontLeftTurn() {          //Functie care executa un viraj de 45 grade la stanga pentru evitarea obstacolelor detectate de senzorul din fata-dreapta
  steer.write(steerLeft);
  motorA.forward(speed);
  motorB.forward(speed);
  delay(90);
  steer.write(neutral);
  //Serial.println("FRONT LEFT TURN");
}

void frontRightTurn() {         //Functie care executa un viraj de 45 grade la dreapta pentru evitarea obstacolelor detectate de senzorul din fata-stanga
  steer.write(steerRight);
  motorA.forward(speed);
  motorB.forward(speed);
  delay(90);
  steer.write(neutral);
  //Serial.println("FRONT RIGHT TURN");
}

void readSidesAndFront() {      //Functia determina daca sunt necesare schimbari scurte sau de 45 de grade.
  readFrontLeft();             //Citește toti senzorii, cu exceptia senzorului frontal, și stabileste daca sunt sau nu necesare corectii minore.
  //Serial.print("Front Left: ");
  //Serial.println(distanceFL);
  delay(3);
  readFrontRight();
  //Serial.print("Front Right: ");
  //Serial.println(distanceFR);
  delay(3);
  readLeft();
  //Serial.print("Left: ");
  //Serial.println(distanceL); //!!!!!!!!!!!!!!!!
  delay(3);
  readRight();
  //Serial.print("Right: ");
  //Serial.println(distanceR);
  if (distanceR < distanceL) {
    readLeft();
    //Serial.print("Left: ");
    //Serial.println(distanceL);
    delay(3);
    readRight();
    //Serial.print("Right: ");
    //Serial.println(distanceR);
      if (distanceR < distanceL) {
        leftTurn();
      }
      else {
        motorA.forward(speed);
        motorB.forward(speed);
        steer.write(neutral);
      }
    }
    else if (distanceL < distanceR) {
    readLeft();
    //Serial.print("Left: ");
    //Serial.println(distanceL);
    delay(3);
    readRight();
    //Serial.print("Right: ");
    //Serial.println(distanceR);
    if (distanceL < distanceR) {
      rightTurn();
    }
    else {
      motorA.forward(speed);
              motorB.forward(speed);
              steer.write(neutral);
    }
    }
else if (distanceFR <= 4) {
  steer.write(steerRight);
      motorA.forward(speed);
              motorB.forward(speed);
  delay(1000);
    motorA.backward(speed);
            motorB.backward(speed);
  //Serial.println("Reversing");
  delay(950);
      motorA.forward(speed);
              motorB.forward(speed);
  steer.write(neutral);
}
else if (distanceFR < frontSideLimit) {
  readFrontRight();
  //Serial.print("Front Right: ");
  //Serial.println(distanceFR);
  if (distanceFR < frontSideLimit) {
    readFrontRight();
    //Serial.print("Front Right: ");
    //Serial.println(distance5);
    if (distanceFR < frontSideLimit) {
      frontLeftTurn();
    }
    else {
    motorA.forward(speed);
            motorB.forward(speed);
      steer.write(neutral);
    }
  }
  else {
    motorA.forward(speed);
            motorB.forward(speed);
    steer.write(neutral);
  }
}
else if (distanceFL <= 4) {
  steer.write(steerRight);
      motorA.forward(speed);
              motorB.forward(speed);
  delay(1000);
    motorA.backward(speed);
            motorB.backward(speed);
  //Serial.println("Reversing");
  delay(950);
      motorA.forward(speed);
              motorB.forward(speed);
  steer.write(neutral);
}
  else if (distanceFL < frontSideLimit) {
    readFrontLeft();
    //Serial.print("Front Left: ");
    //Serial.println(distanceFL);
    if (distanceFL < frontSideLimit) {
      readFrontLeft();
      // Serial.print("Front Left: ");
      // Serial.println(distanceFL);
      if (distanceFL < frontSideLimit) {
        frontRightTurn();
      }
      else {
        motorA.forward(speed);
        motorB.forward(speed);
        steer.write(neutral);
      }
    }
    else {
      motorA.forward(speed);
      motorB.forward(speed);
      steer.write(neutral);
    }
  }
}

void loop() {
  steer.write(neutral);
  motorA.forward(speed);
  motorB.forward(speed);

  readFront();
  //Serial.print("Forward Reading: ");    //Aveam probleme când mașina se întoarse aleatoriu chiar și atunci când nu era prezent niciun obiect.
  //Serial.println(distanceF);             // Acest lucru sa datorat zgomotului din citirile senzorilor.
  delay(8);                             //Cele 4 declaratii se vor asigura ca exista un obstacol înainte de a vira.
  if (distanceF < frontLimit) {
    readFront();
    //Serial.print("Forward Reading: ");
    //Serial.println(distanceF);
    delay(8);
    if (distanceF < frontLimit ) {
      readFront();
      //Serial.print("Forward Reading: ");
      //Serial.println(distanceF);
      delay(8);
      if (distanceF < frontLimit) {
        readFront();
        //Serial.print("Forward Reading: ");
        //Serial.println(distanceF);
        delay(8);
        if (distanceF > frontLimit) {
          motorA.forward(speed);
          motorB.forward(speed);
          steer.write(neutral);
        }
        else {            //masina citeste cele două laturi si decide care dintre ele are mai mult spatiu.
          readRight();
          readLeft();
          if (distanceL > distanceR ) {
            longLeftTurn();
          }
          else if (distanceR > distanceL) {
            longRightTurn();
          }
          readFront();                         //In cazul in care distanta fata de obiectul din fata e prea mica (<5cm), masina va merge inapoi.
          if (distanceF <= 5 ) {
            motorA.forward(speed);
            motorB.forward(speed);
            delay(1000);
            motorA.backward(speed);
            motorB.backward(speed);
            //Serial.println("Reversing");
            delay(950);
            motorA.forward(speed);
            motorB.forward(speed);
            steer.write(neutral);
          }
        }
      }
      else {
        readSidesAndFront();    // In cazul in care verificarile multiple pentru un perete în fata nu reusesc, masina citeste restul senzorilor pentru ajustari minore.
      }
    }
    else {
      readSidesAndFront();
    }
  }
  else {
    readSidesAndFront();
  }
  //delay(1000);
}
