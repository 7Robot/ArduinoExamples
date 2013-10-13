/*
  Blink
  Turns on a LED for one second,
  then off for one second, repeatedly.
 */




// Declaration of constants and variables :

// mapping of the pins
const int ledPin = 13; // pin number 13 refers to led




// put your setup code here, to run once:

void setup() {                
  // initialize the digital pin as an output.
  // ledPin refers to pin number 13.
  pinMode(ledPin, OUTPUT);     
}




// put your main code here, to run repeatedly: 

void loop() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second
}
