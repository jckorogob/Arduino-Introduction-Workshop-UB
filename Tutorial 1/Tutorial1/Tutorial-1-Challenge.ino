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
* 
* This takes in 3 HI LO inputs and outputs colors according to the signals sent
* 
* Timerange is a time range in seconds
*/

void color(int a, int b, int c, int timerange){

  int randomDelay = random(1000, timerange*100); 
  
  delay(randomDelay);
  
  digitalWrite(9, a); digitalWrite(10, b); digitalWrite(11, c);
  
} 
