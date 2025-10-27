Tutorial 1: Blinking LED

Overview:
  * Learn to control an LED with Arduino. The provided code makes the LED blink once per second. Your task: make it flash 5 random colors at random intervals (1-10 seconds).

Components
  * Arduino Uno
  * Breadboard
  * RGB LED
  * 330Ω resistor
  * Jumper wires
  * USB cable

Circuit (see Circuit1.png)

  * LED cathode (Long Leg) → GND
  * R G B Legs (Shorter Legs) → 330Ω Resistor → R = pin 11, G = pin 10, B = pin 9

Code Explanation

#define RED 11

#define BLUE 10

#define GREEN 9

void setup() {

  pinMode(RED, OUTPUT);  // Set RED pin 11 as output
  
  pinMode(GREEN, OUTPUT);  // Set GREEN pin 10 as output
  
  pinMode(BLUE, OUTPUT);  // Set BLUE pin 9 as output
  
}



void loop() {

 digitalWrite(RED, HIGH);  // Turn LED on RED

 delay(1000);              // Wait 1 second

 digitalWrite(RED, LOW);   // Turn LED off

 delay(1000);              // Wait 1 second

}


Your Challenge

  For random timing:

  * Open the Tutorial-1-Challenge.ino file

Troubleshooting

* LED not lighting? Check polarity (long leg = -)

* LED dim? Verify 330Ω resistor

* Upload fails? Check Tools → Board → Arduino Uno









