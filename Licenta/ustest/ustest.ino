//////////////// PRUEBA DEL HC - SR04 //////////////

// Prueba del sensor de distancia por ultrasonidos HC - SR04

// Harware: Uno, HC - SR04 conectado "directamente" a los pines:

//  GND - GND
//  13  - Echo
//  12  - Trigger
//  11  - Vcc
//  
//(Se hace así para poder conectar el HC - SR04 directamente sobre el conector del "uno").

// CONSTANTES //

const int Anode = 11;
const int Echo = 10;
const int Trigger = 9;

float distance;
unsigned long duration;

void setup() 
{

Serial.begin(115200); 
  
pinMode(Anode, OUTPUT);
digitalWrite(Anode, HIGH);

pinMode(Trigger, OUTPUT);
digitalWrite(Trigger, LOW);

pinMode(Echo, INPUT);
}

void loop() {

digitalWrite(Trigger, HIGH);
delayMicroseconds (50);
digitalWrite(Trigger, LOW);



duration = pulseIn(Echo, HIGH);
distance = duration / 58.0;

Serial.print ("duration: ");
Serial.print (duration);
Serial.print ("   distance: ");
Serial.println (distance,1);
  
delay(2000);
  
}
