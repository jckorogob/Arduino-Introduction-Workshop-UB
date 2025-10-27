int colorMode = 0;
int lastButtonState = HIGH;

void setup(){
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT_PULLUP);  // Built-in pull-up resistor
}

void loop(){
  int buttonState = digitalRead(2);

  if(buttonState == LOW) {
    showRed(); delay(500);
    showGreen(); delay(500);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}

void showRed() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void showGreen() {
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
