// Use up to 4 7-segments display at the same time
// could be used for the KronoCuSec

//################################################################
//                        Variables
//################################################################

// matrix that will be used to configure the pins
// to use for each digit or letter
byte seven_seg_digits[11][7] = {
//{a,b,c,d,e,f,g}
  {0,0,0,0,0,0,1}, // = 0
  {1,0,0,1,1,1,1}, // = 1
  {0,0,1,0,0,1,0}, // = 2
  {0,0,0,0,1,1,0}, // = 3
  {1,0,0,1,1,0,0}, // = 4
  {0,1,0,0,1,0,0}, // = 5
  {0,1,0,0,0,0,0}, // = 6
  {0,0,0,1,1,1,1}, // = 7
  {0,0,0,0,0,0,0}, // = 8
  {0,0,0,0,1,0,0}, // = 9
  {1,1,1,1,1,1,1} // tout éteint
};

// other variables
int i;
int pin; // variable that will be used each time we configure a pin
long time; // to use with millis() function
int timeTable[4]; // contains the time [*10s, *1s, *100ms, *10ms]


//################################################################
//              Procedures and functions
//################################################################

// configure pins (starting at firstPin) to write a digit on displays
void preDisplay(int digit, int firstPin) {
  for (pin = firstPin ; pin < firstPin + 7 ; pin++) {
    // digit matches a row and first column must be 0 so pin-firstPin
    digitalWrite(pin, seven_seg_digits[digit][pin-firstPin]);
  } 
}


// displays a digit on a uniq 7-segments display
// firstCommandPin and nbOfCommandPins indicates the pins to use to turn on or off the displays
// for example if firstCommandPin=9 and nbOfCommandPins=4 we should command pins 9-10-11-12
// firstDigitPin matches the first of 7 pins to configure digits
void displays(int segmentedDisplayNb, int firstCommandPin, int nbOfCommandPins, int digit, int firstDigitPin) {
  
  // turn off all displays
  for (pin = firstCommandPin ; pin < firstCommandPin + nbOfCommandPins ; pin ++) {
    digitalWrite(pin, 0);
  }
  
  // pre-display
  preDisplay(digit, firstDigitPin);
  
  // turn on the good 7-segments display
  digitalWrite(firstCommandPin + segmentedDisplayNb - 1,HIGH);
}


// displays the 4 digits on the 4 displays
// refreshTime matches the time between one turn on and the next
void multiDisplay(int digits[], int nbOfDigits, int firstDigitPin, int firstCommandPin, int refreshTime){
  for (i = 0; i < nbOfDigits; i++) {
    displays(i+1, firstCommandPin, nbOfDigits, digits[i], firstDigitPin);
    delay(refreshTime/nbOfDigits);
  }
}


// transform a time in ms to a table with 4 values [10s, s, 100ms, 10ms]
void time2Table(long time, int timeTable[]){
  // 10e-2 s
  timeTable[3] = (time%100)/10;
  // 10e-1 s
  timeTable[2] = (time%1000)/100;
  // 1 s
  timeTable[1] = (time%10000)/1000;
  // 10 s
  timeTable[0] = (time%100000)/10000;
}


//################################################################
//                      Initialisation
//################################################################

void setup() 
{
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  // configuration of serial port
  Serial.begin(9600); // open a serial port
}


//################################################################
//                      Main programm
//################################################################

void loop() 
{
  time = millis();
  time2Table(time, timeTable);
  multiDisplay(timeTable, 4, 2, 9, 25);
}
