// Using an RGB led coupled with light sensors

// maping of the pin connections
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

const int redLedPin = 11;
const int greenLedPin = 9;
const int blueLedPin = 10;

// other usefull constants
const int baudRate = 9600; // in bits/s
const int sensorLow = 400;
const int sensorHigh = 900;

// variables
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup(){
  // configuration of the pin modes
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  
  // configuration of serial port
  Serial.begin(baudRate); // open a serial port
}

// main program
void loop(){
  redSensorValue = analogRead(redSensorPin);
  delay(5); // the ADC takes about a millisecond to do its work
  greenSensorValue = analogRead(greenSensorPin);
  delay(5); // the ADC takes about a millisecond to do its work
  blueSensorValue = analogRead(blueSensorPin);
  delay(5); // the ADC takes about a millisecond to do its work
  
  Serial.print("Raw sensors values");
  Serial.print("\t Red : ");
  Serial.print(redSensorValue);
  Serial.print("\t Green : ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue : ");
  Serial.println(blueSensorValue);
  
  // from 0-1023 to 0-255 values (PWM need 0-255 values)
  redValue = map(redSensorValue, sensorLow, sensorHigh, 0, 200);
  greenValue = map(greenSensorValue, sensorLow, sensorHigh, 50, 255);
  blueValue = map(blueSensorValue, sensorLow, sensorHigh, 0, 20);
  
  Serial.print("Modified values");
  Serial.print("\t Red : ");
  Serial.print(redValue);
  Serial.print("\t Green : ");
  Serial.print(greenValue);
  Serial.print("\t Blue : ");
  Serial.println(blueValue);
  
  // light up the RGB led
  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);
}
