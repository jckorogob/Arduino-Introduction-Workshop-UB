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
