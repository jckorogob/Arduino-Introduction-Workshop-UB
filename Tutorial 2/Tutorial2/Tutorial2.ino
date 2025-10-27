// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 2;  				// the number of the pushbutton pin
const int LED_PIN1 =  11;  			  // the number of the LED pin
const int LED_PIN2 =  12;  
const int LED_PIN3 =  13;  
// variables will change:
int buttonState = 0;   						// variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  // initialize the pushbutton pin as an pull-up input:
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);

  // control LED according to the state of button
  if(buttonState == LOW){         // If button is pressing
    digitalWrite(LED_PIN1, HIGH);  // turn on LED
  } else {                        // otherwise, button is not pressing
    digitalWrite(LED_PIN1, LOW);   // turn off LED
	}  
}