// this program uses 1 green led, 2 red led and a push button

// mapping of the pins
const int switchButton = 2;
const int greenLed = 7;
const int redLed1 = 10;
const int redLed2 = 12;

// state of the switch button
int switchState = 0;

// configuration of the pin modes
void setup(){
  pinMode(switchButton, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
}

// main program : make red led blinking when the button is pressed
void loop(){
  switchState = digitalRead(switchButton);
  
  if (switchState == LOW) { // the button is not pressed
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
  } else { // the button is pressed
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, LOW);
    delay(250); // time (in ms) while do nothing
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, HIGH);
    delay(250); // time (in ms) while do nothing
  }
}
