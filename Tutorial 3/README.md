Tutorial 3: Servo Motor Control with Potentiometer

What You'll Learn
* In this tutorial, you'll learn how to control a servo motor using a potentiometer (rotary knob). This demonstrates analog input reading and PWM output control - two fundamental Arduino concepts.

Components Needed
* Arduino Uno
* Servo motor (SG90 or similar)
* Potentiometer (10kΩ)
* Breadboard
* Jumper wires

Circuit Overview
* Servo Motor Signal Wire → Arduino Pin 9 (PWM)
* Servo Power (Red) → 5V
* Servo Ground (Brown/Black) → GND
* Potentiometer Middle Pin → Arduino Pin A0 (Analog Input)
* Potentiometer Outer Pins → 5V and GND

How It Works
* The potentiometer acts as a variable voltage divider. As you turn the knob:
* Arduino reads the analog voltage (0-5V) from pin A0
* The analogRead() function converts this to a value between 0-1023
* The map() function converts this range to 0-180 degrees
* The servo motor rotates to match the knob position


Your Challenge
* The provided code makes the servo follow the potentiometer position smoothly.

Try these modifications:
* Make the servo move in the opposite direction of the knob
* Limit the servo's range to only 0-90 degrees instead of 0-180
* Add a "dead zone" in the middle where the servo doesn't move
* Make the servo move in discrete steps (every 30 degrees) instead of smoothly

Advanced: Add an LED that turns on when the servo reaches certain positions


Key Concepts
* Analog Input: Reading variable voltage levels
* PWM (Pulse Width Modulation): How servos are controlled
* Map Function: Converting one range of values to another
* Servo Library: Built-in Arduino library for servo control

Tips
* Servo motors draw significant current - if your servo jitters or behaves oddly, it may need external power
* The servo will try to hold its position even when not moving
* Experiment with the delay value to see how it affects responsiveness


