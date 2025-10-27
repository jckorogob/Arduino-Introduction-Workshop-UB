/*
 * Button Test Program for Arduino Uno + LCD
 * 
 * This will help you test if your buttons are working correctly
 * 
 * WIRING:
 * LCD:
 * - RS → Pin 12
 * - E → Pin 11
 * - D4 → Pin 5
 * - D5 → Pin 4
 * - D6 → Pin 3
 * - D7 → Pin 2
 * - VSS → GND
 * - VDD → 5V
 * - V0 → Potentiometer (contrast)
 * 
 * BUTTONS:
 * - Button 1 (LEFT) → Pin 6 to GND
 * - Button 2 (RIGHT) → Pin 7 to GND
 */

#include <LiquidCrystal.h>

// Initialize LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define BUTTON_LEFT 6
#define BUTTON_RIGHT 7

int leftCount = 0;
int rightCount = 0;
bool leftPressed = false;
bool rightPressed = false;

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Button Test");
  lcd.setCursor(0, 1);
  lcd.print("L:0     R:0");
  
  // Setup buttons with internal pull-up resistors
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  
  delay(1000);
}

void loop() {
  // Read left button (LOW = pressed with pull-up)
  if(digitalRead(BUTTON_LEFT) == LOW) {
    if(!leftPressed) {
      leftPressed = true;
      leftCount++;
      updateDisplay();
    }
  } else {
    leftPressed = false;
  }
  
  // Read right button (LOW = pressed with pull-up)
  if(digitalRead(BUTTON_RIGHT) == LOW) {
    if(!rightPressed) {
      rightPressed = true;
      rightCount++;
      updateDisplay();
    }
  } else {
    rightPressed = false;
  }
  
  delay(50); // Small delay for debouncing
}

void updateDisplay() {
  lcd.setCursor(0, 0);
  lcd.print("Button Test     ");
  
  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(leftCount);
  lcd.print("     ");
  
  lcd.setCursor(8, 1);
  lcd.print("R:");
  lcd.print(rightCount);
  lcd.print("     ");
}
