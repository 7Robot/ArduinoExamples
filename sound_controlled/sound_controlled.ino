// Piezo controlled by potentiometer (frequency)

// maping of the pin connections
const int potPin = A2; // will use to control frequency
const int piezoPin = 10;
const int ledPin = 13;

// other usefull constants
const int baudRate = 9600; // in bits/s
const int duration = 20; // how long (ms) to play the sound

// variables
int potVal;
int pitch;
int potLow = 1023;
int potHigh = 0;

void setup(){
  // configuration of the pin modes
  pinMode(ledPin, OUTPUT);
  
  // initialization of led for calibration
  digitalWrite(ledPin, HIGH); // first light up the led
  
  // calibrating lower and higher values of sensor (here potentiometer)
  while(millis()<5000) { // during the first 5 seconds
    potVal = analogRead(potPin);
    if (potVal > potHigh) {
      potHigh = potVal;
    }
    if (potVal < potLow) {
      potLow = potVal;
    }
  }
  
  // signal with led end of calibration
  digitalWrite(ledPin, LOW);
  
  // configuration of serial port
  Serial.begin(baudRate); // open a serial port
}

// main program
void loop(){
  potVal = analogRead(potPin);
  pitch = map(potVal, potLow, potHigh, 50, 4000);
  tone(piezoPin, pitch, duration);
  
  Serial.print("potVal : ");
  Serial.print(potVal);
  Serial.print("\t pitch : ");
  Serial.println(pitch);
  
  delay(10);
}
