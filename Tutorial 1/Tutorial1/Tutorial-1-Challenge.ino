#define RED 9
#define BLUE 10
#define GREEN 11

void setup() {
  pinMode(RED, OUTPUT);  // Set RED pin 9 as output
  pinMode(GREEN, OUTPUT);  // Set GREEN pin 10 as output
  pinMode(BLUE, OUTPUT);  // Set BLUE pin 11 as output
}
 
void loop() {
 //This loop repeats the sequence of colors you create 20 times
  for(int i = 0; i < 20; i++){
    //Enter 4 numbers into this function call the first 3 should be 1's or 0's the last on should be a maximum random time in seconds
    //Example: color(LOW, HIGH, LOW, 5)
    //that will make the LED flash blue at random time intervals between 1 and 5 secnds
    color(HIGH,LOW,LOW,10);
    //Add more color function calls below to create a variety of flashing colors with different time increments
    //   |
    //   |
    //  \/ Add Here
    
  } 
}

/*
* Color Function
* 
* This takes in 3 HI LO inputs and outputs colors according to the signals sent
* 
* Timerange is a time range in seconds
*/

void color(int a, int b, int c, int timerange){

  int randomDelay = random(1000, timerange*100); 
  
  delay(randomDelay);
  
  digitalWrite(RED, a); digitalWrite(GREEN, b); digitalWrite(BLUE, c);
  
} 
