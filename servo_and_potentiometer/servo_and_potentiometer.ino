// Servo controlled by potentiometer

// include usefull librairies
#include <Servo.h>

// maping of the pin connections
const int potPin = A0;
const int servoPin = 9;

// other usefull constants
const int baudRate = 9600; // in bits/s

// variables
Servo servo;
int potVal;
int angle;

void setup(){
  // configuration of the pin modes
  servo.attach(servoPin);
  
  // configuration of serial port
  Serial.begin(baudRate); // open a serial port
}

// main program
void loop(){
  potVal = analogRead(potPin);
  delay(5); // the ADC takes about a millisecond to do its work
  angle = map(potVal, 0, 1023, 0, 179);
  
  Serial.print("potVal : ");
  Serial.print(potVal);
  Serial.print("\t angle : ");
  Serial.println(angle);
  
  servo.write(angle);
  delay(15);
}
