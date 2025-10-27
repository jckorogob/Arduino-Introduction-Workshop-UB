/* Servo motor with potentiometer and Arduino example code. More info: https://www.makerguides.com/ */

#include "Servo.h" // include the required Arduino library

#define servoPin 9 // Arduino pin for the servo
#define potPin A0 // Arduino pin for the potentiometer

int angle = 0; // variable to store the servo position in degrees
int reading = 0; // variable to store the reading from the analog input

Servo myservo; // create a new object of the servo class

void setup() {
  myservo.attach(servoPin);
}

void loop() {
  reading = analogRead(potPin); // read the analog input
  angle = map(reading, 0, 1023, 0, 180); // map the input to a value between 0 and 180 degrees
  myservo.write(angle); // tell the servo to go to the set position
  delay(15); // wait 15 ms for the servo to reach the position
}