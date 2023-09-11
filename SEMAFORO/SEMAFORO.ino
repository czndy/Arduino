/*
  Arduino Starter Kit example
  Project 2 - Spaceship Interface

  This sketch is written to accompany Project 2 in the Arduino Starter Kit

  Parts required:
  - one green LED
  - two red LEDs
  - pushbutton
  - 10 kilohm resistor
  - three 220 ohm resistors

  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

// Create a global variable to hold the state of the switch. This variable is
// persistent throughout the program. Whenever you refer to switchState, you’re
// talking about the number it holds
//int switchstate = 0;

void setup() {
  // declare the LED pins as outputs
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // declare the switch pin as an input
  //pinMode(4, INPUT);
}

void loop() {

  // read the value of the switch
  // digitalRead() checks to see if there is voltage on the pin or not
  // switchstate = digitalRead(4);

  // if the button is not pressed turn on the green LED and off the red LEDs
  // if (switchstate == LOW) {
  //   digitalWrite(5, HIGH);  // turn the green LED on pin 3 on
  //   digitalWrite(6, LOW);   // turn the red LED on pin 4 off
  //   digitalWrite(7, LOW);   // turn the red LED on pin 5 off
  // }
  // this else is part of the above if() statement.
  // if the switch is not LOW (the button is pressed) turn off the green LED and
  // blink alternatively the red LEDs
  // else {
    
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
    delay(5000);
    digitalWrite(5, LOW); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, LOW);
    delay(2000);
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH); 
    delay(5000);
  // }
}
