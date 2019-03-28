const int encoderPin= A5;

int encoderVal = 0;

void setup()
{
pinMode(encoderPin, INPUT);
Serial.begin(9600); // initialize serial communications at 9600 bps

}

void loop()
{
int change = getEncoderTurn();
encoderVal = encoderVal + change;
Serial.println(encoderVal);
}

int getEncoderTurn(void)
{
static int oldA = HIGH; //set the oldA as HIGH
int result = 0;
int newA = digitalRead(encoderPin);//read the value of encoderPin to newA
if (newA != oldA) //if the value of encoderPin or the dtPin has changed
{
// something has changed
if (oldA == HIGH && newA == LOW)
result++;
}
oldA = newA;
return result;
}
