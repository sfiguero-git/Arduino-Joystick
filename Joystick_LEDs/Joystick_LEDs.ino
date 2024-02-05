// @author Saul Figueroa.

// Analog in:
#define xPin A0 
#define yPin A1 

int buttonPin = 13;    // Pushbutton (joystick) connected to digital pin 13.

// Set up a resistor for common ground; that is, connect all the cathodes with a resistor for fast prototyping.

// For anodes:
int upLED = 12;    // LED connected to digital pin 12.
int rightLED = 11;    // LED connected to digital pin 11.
int downLED = 10;    // LED connected to digital pin 10.
int leftLED = 9;    // LED connected to digital pin 9.
int pressed = 0;      // Variable to store the state of the joystick. 0 when pressed, 1 otherwise.
int xAxis = 0; // X axis value will be stored here.
int yAxis = 0; // Y axis value will be stored here.

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); // sets the digital pin 13 as input.

  pinMode(upLED, OUTPUT); // sets the digital pin 12 as output.
  pinMode(rightLED, OUTPUT); // sets the digital pin 11 as output.
  pinMode(downLED, OUTPUT); // sets the digital pin 10 as output.
  pinMode(leftLED, OUTPUT); // sets the digital pin 9 as output.
}

void loop() {
  xAxis = analogRead(xPin);
  yAxis = analogRead(yPin);

  digitalWrite(upLED, 0);
  digitalWrite(rightLED, 0);
  digitalWrite(downLED, 0);
  digitalWrite(leftLED, 0);
  
  /*
  Consider:
  x axis can have values from 0 to 1023, from left to right.
  y axis can have values from 0 to 1023, from up to down.

  */

  // Cases:
  if (yAxis < 500){
    digitalWrite(upLED, 1);
  }

  if (yAxis > 524){
    digitalWrite(downLED, 1);
  }

  if (xAxis < 500){
    digitalWrite(leftLED, 1);
  }

  if (xAxis > 524){
    digitalWrite(rightLED, 1);
  }

  if (digitalRead(buttonPin) == 0){ // Light up all the LEDs!
    digitalWrite(upLED, 1);
    digitalWrite(rightLED, 1);
    digitalWrite(downLED, 1);
    digitalWrite(leftLED, 1);
  }
  delay(100); // Can be modified as necessary.
}
