// this program uses leds and a temperature sensor

// mapping of the connections
const int tempSensorPin = A0;
const int greenLed = 7;
const int yellowLed = 10;
const int redLed = 12;

// other usefull constants
const int baudRate = 9600; // in bits/s
const float maxVoltage = 5.0; // max voltage in analog input pin
const float maxValueAnalogInput = 1024.0; // max value in analog input pin

const float baselineTemp = 26.0;
const float step1 = baselineTemp;
const float step2 = step1 + 2;
const float step3 = step2 + 2;
const float step4 = step3 + 2;

// variables
int tempSensorVal = 0;
float voltage = 0.0;
float temperature = 0.0;

void setup(){
  // configuration of the pin modes
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  // configuration of initial lighting (off)
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
  
  // configuration of serial port
  Serial.begin(baudRate); // open a serial port
}

// main program : light leds depending on temperature
void loop(){
  tempSensorVal = analogRead(tempSensorPin);
  Serial.print("Temperature sensor value : ");
  Serial.print(tempSensorVal);
  
  voltage = (tempSensorVal/maxValueAnalogInput)*maxVoltage;
  Serial.print(", Volt : ");
  Serial.print(voltage);
  Serial.print("V");
  
  temperature = (voltage - 0.5)*100; // coeff from datasheet
  Serial.print(", degrees C : ");
  Serial.println(temperature);
  
  // turn the leds on depending on temperature
  if (temperature < step1) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  } else if (temperature < step2) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  } else if (temperature < step3) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
  } else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, HIGH);
  }
  delay(1);
}
