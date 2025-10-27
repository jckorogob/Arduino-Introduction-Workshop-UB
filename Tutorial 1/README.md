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

cppvoid setup() {

&nbsp; pinMode(13, OUTPUT);  // Set pin 13 as output

}



void loop() {

&nbsp; digitalWrite(13, HIGH);  // Turn LED on

&nbsp; delay(1000);             // Wait 1 second

&nbsp; digitalWrite(13, LOW);   // Turn LED off

&nbsp; delay(1000);             // Wait 1 second

}

Your Challenge

For random timing:

cpp// In setup():

randomSeed(analogRead(0));



// In loop():

int randomDelay = random(1000, 10001);  // 1-10 seconds

delay(randomDelay);

For RGB LED colors:

Connect Red, Green, Blue to pins 9, 10, 11 (each with 220Ω resistor):

cpp// Red

digitalWrite(9, HIGH); digitalWrite(10, LOW); digitalWrite(11, LOW);



// Green  

digitalWrite(9, LOW); digitalWrite(10, HIGH); digitalWrite(11, LOW);



// Blue

digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, HIGH);



// Yellow

digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(11, LOW);



// Purple

digitalWrite(9, HIGH); digitalWrite(10, LOW); digitalWrite(11, HIGH);

Pick random colors:

cppint colorChoice = random(0, 5);  // 0-4 for 5 colors

Troubleshooting



LED not lighting? Check polarity (long leg = +)

LED dim? Verify 220Ω resistor

Upload fails? Check Tools → Board → Arduino Uno

