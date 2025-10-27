Tutorial 2: Button-Controlled LED

Overview:
* Add a button to control your LED. The provided code turns the LED on when pressed, off when released.

Your task: make the LED flash different colors when the button is pressed.

Components
* Arduino Uno
* Breadboard
* LED (RGB LED recommended)
* Push button
* 220Ω resistor
* Jumper wires
* USB cable



Circuit (see Circuit2.png)

LED:

LED cathode → GND
LED Cathode → 330Ω resistor → Pin 13


Button:



Button pin 1 → Pin 2

Button pin 2 (diagonal) → GND



Code Explanation

cppconst int BUTTON\_PIN = 2;

const int LED\_PIN = 13;

int buttonState = 0;



void setup() {

&nbsp; pinMode(LED\_PIN, OUTPUT);

&nbsp; pinMode(BUTTON\_PIN, INPUT\_PULLUP);  // Built-in pull-up resistor

}



void loop() {

&nbsp; buttonState = digitalRead(BUTTON\_PIN);

&nbsp; 

&nbsp; if(buttonState == LOW) {       // Button pressed (connected to GND)

&nbsp;   digitalWrite(LED\_PIN, HIGH);

&nbsp; } else {

&nbsp;   digitalWrite(LED\_PIN, LOW);

&nbsp; }

}

INPUT\_PULLUP: Pin reads HIGH when button not pressed, LOW when pressed (no external resistor needed).

Your Challenge

Option 1: Cycle colors on each press

OR

Option 2: Hold button for color sequence

Open Tutorial-2-Challenge.ino

Troubleshooting



Button not responding? Check connections to Pin 2 and GND

Erratic behavior? Add debouncing (50ms delay between reads)

Wrong colors? Verify RGB LED is common cathode type



Advanced Ideas



Debouncing for cleaner button detection

Long press (2+ sec) for different patterns

PWM with analogWrite() for fading effects



