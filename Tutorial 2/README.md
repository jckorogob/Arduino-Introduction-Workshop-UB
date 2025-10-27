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

* LED cathode (Long Leg) → GND
* R G B Legs (Shorter Legs) → 330Ω Resistor → R = pin 11, G = pin 10, B = pin 9

Button:

* Button (Bottom Right Leg) → GND
* Button (Bottom Left Leg) → Pin 2

Code Explanation

#define RED 11
#define BLUE 10
#define GREEN 9
#define BTN 2

int buttonState;

void setup() {
  pinMode(RED, OUTPUT);        // Set RED pin 11 as output
  pinMode(GREEN, OUTPUT);      // Set GREEN pin 10 as output
  pinMode(BLUE, OUTPUT);       // Set BLUE pin 9 as output
  pinMode(BTN, INPUT_PULLUP);  // Built-in pull-up resistor
}

void loop(){
  buttonState = digitalRead(BTN);

  if(buttonState == LOW) {
    digitalWrite(RED, HIGH); 
  } else {
    digitalWrite(RED,LOW); 
  }
}

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





