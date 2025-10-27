# Tutorial 4: LCD Display and Button Input

## What You'll Learn

* In this tutorial, you'll learn how to use a 16x2 LCD display to show text and read button inputs. This combines visual output with user interaction - essential for any Arduino project interface.



Components Needed
* Arduino Uno
* 16x2 LCD Display (with parallel interface)
* 2x Push buttons
* 10kΩ Potentiometer (for LCD contrast)
* Breadboard
* Jumper wires

Circuit Overview

LCD Connections (Standard Parallel Mode)

* VSS → GND
* VDD → 5V
* V0 → Potentiometer middle pin (contrast control)
* RS → Arduino Pin 12
* RW → GND
* E → Arduino Pin 11
* D4 → Arduino Pin 5
* D5 → Arduino Pin 4
* D6 → Arduino Pin 3
* D7 → Arduino Pin 2
* A (Backlight +) → 5V
* K (Backlight -) → GND

Button Connections

* Button (Bottom Right Leg) → GND
* Button (Bottom Left Leg) → Pin 2



Part 1: Basic LCD Display (Tutorial4-1.ino)

This code demonstrates basic LCD text display:

Displays text on both rows of the LCD
Shows text for 4 seconds, then clears
Waits 5 seconds and repeats

Key Functions:

lcd.begin(16, 2);        //Initialize 16 columns, 2 rows

lcd.setCursor(col, row); //Set cursor position

lcd.print("text");       //Display text

lcd.clear()              //Clear the entire display



Part 2: Button Input Testing (Tutorial4-2.ino)

This code helps you test your button connections:
* Displays "Button Test" on the screen
* Shows counters for left (L:) and right (R:) button presses
* Uses internal pull-up resistors (no external resistors needed!)
* Includes debouncing to prevent false triggers

Key Concepts:

* INPUT_PULLUP - Activates internal pull-up resistors
* Button reads LOW when pressed (with pull-up)
* Debouncing - Preventing multiple reads from one press

Your Challenges

Easy:

1. Change the text that displays on the LCD

2. Make the LCD display your name and a custom message

3. Make the text blink on and off at different intervals

4. Display the current button count on the LCD



Medium:

1. Create a simple menu system that changes when you press buttons

2. Make a counter that increments with one button and decrements with the other

3. Display a scrolling message that moves across the screen

4. Create a reaction time game - display "GO!" and measure how fast you press the button


Advanced:

1. Create a simple calculator that lets you select numbers and operations with buttons

2. Build a two-player game where each player has a button and score is displayed

3. Make a password system where you must press buttons in a specific sequence

4. *Challenge: Combine Tutorial 3 and 4 - display the servo angle on the LCD!



Key Concepts

* LCD Display: Visual output for projects

* Cursor Positioning: Controlling where text appears

* Button Input: Reading user interaction

* Pull-up Resistors: Internal resistors that make button reading easier

* Debouncing: Cleaning up noisy button signals

* String Formatting: Combining text and numbers for display



Troubleshooting

* Can't see text? Adjust the potentiometer to change contrast

* Buttons not working? Check that you're using INPUT_PULLUP mode

* Garbled characters? Check all LCD data pin connections (D4-D7)

* No backlight? Verify A and K pins are connected to 5V and GND


Why This Matters

* LCD displays are one of the most common ways to show information from your Arduino. Combined with buttons for input, you can create complete user interfaces for standalone projects without needing a computer connection!



