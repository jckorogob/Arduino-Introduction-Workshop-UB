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

Copy Paste this code block 

//-----------------------------------------------------------------------------

void setup() {
 pinMode(11, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(9, OUTPUT);
}
 
void loop() {
  for(int i = 0; i < 20; i++){
    //Enter 4 numbers into this function call the first 3 should be 1's or 0's the last on should be a maximum random time in seconds
    color(1,0,0,10);
  }
}

/*
* Color Function
* This takes in 3 HI LO inputs and outputs colors according to the signals sent
* Timerange is a time range in seconds
*/
void color(int a, int b, int c, int timerange){
  int randomDelay = random(1000, timerange*100); 
  delay(randomDelay);
  digitalWrite(9, a); digitalWrite(10, b); digitalWrite(11, c);
} 


//--------------------------------------------------------------------------------

Troubleshooting



LED not lighting? Check polarity (long leg = +)

LED dim? Verify 220Ω resistor

Upload fails? Check Tools → Board → Arduino Uno



