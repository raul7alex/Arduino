 const int analogTemp = A0; //temperature input pin


 void setup()
{
  //start serial communication
  Serial.begin(9600);
}

void loop()
{
  int tempRead = analogRead(analogTemp); //read analog value

  Serial.println(tempRead); //print value to serial port
 // delay(1000); //wait 10 seconds before new reading
}
