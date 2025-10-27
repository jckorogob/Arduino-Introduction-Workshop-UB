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
  buttonState = digitalRead(2);

  if(buttonState == LOW) {
    showRed();
    showGreen();
  } else {
    //Turns LED off
    clear();
  }
}
//copy the format of these functions to create new functions (Change the signals from HIGH to LOW and test them out)
void clear(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(500);
}

void showRed() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(500);
}

void showGreen() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  delay(500);
}
