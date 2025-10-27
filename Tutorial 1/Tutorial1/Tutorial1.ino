#define RED 9
#define BLUE 10
#define GREEN 11

void setup() {
  pinMode(RED, OUTPUT);  // Set RED pin 9 as output
  pinMode(GREEN, OUTPUT);  // Set GREEN pin 10 as output
  pinMode(BLUE, OUTPUT);  // Set BLUE pin 11 as output
}

void loop() {
 digitalWrite(RED, HIGH);  // Turn LED on RED
 delay(1000);              // Wait 1 second
 digitalWrite(RED, LOW);   // Turn LED off
 delay(1000);              // Wait 1 second
}
