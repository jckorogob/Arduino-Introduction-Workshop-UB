Tutorial 1: LED Blinking

Overview

Learn to control an LED with Arduino. The provided code makes the LED blink once per second. Your task: make it flash 5 random colors at random intervals (1-10 seconds).

Components



Arduino Uno

Breadboard

LED (RGB LED recommended)

220Ω resistor

Jumper wires

USB cable



Circuit (see Circuit1.png)



LED anode (long leg) → 220Ω resistor → Pin 13

LED cathode (short leg) → GND



Code Explanation

void setup() {

  pinMode(11, OUTPUT);  // Set pin 13 as output

}



void loop() {

 digitalWrite(11, HIGH);  // Turn LED on

 delay(1000);             // Wait 1 second

 digitalWrite(11, LOW);   // Turn LED off

 delay(1000);             // Wait 1 second

}

Your Challenge

For random timing:

Open the Tutorial-1-Challenge.ino file

Troubleshooting



LED not lighting? Check polarity (long leg = +)

LED dim? Verify 220Ω resistor

Upload fails? Check Tools → Board → Arduino Uno




