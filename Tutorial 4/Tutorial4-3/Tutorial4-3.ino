/*
 * Snake Game for Arduino Uno + 16x2 LCD
 * 
 * WIRING INSTRUCTIONS FOR TINKERCAD:
 * 
 * LCD CONNECTIONS:
 * LCD VSS (GND) → Arduino GND
 * LCD VDD (5V)  → Arduino 5V
 * LCD V0 (Contrast) → Potentiometer middle pin (outer pins to 5V and GND)
 * LCD RS  → Arduino Pin 12
 * LCD RW  → Arduino GND
 * LCD E   → Arduino Pin 11
 * LCD D4  → Arduino Pin 5
 * LCD D5  → Arduino Pin 4
 * LCD D6  → Arduino Pin 3
 * LCD D7  → Arduino Pin 2
 * LCD A (Backlight +) → Arduino 5V
 * LCD K (Backlight -) → Arduino GND
 * 
 * BUTTON CONNECTIONS (with internal pull-up resistors):
 * Button 1 (LEFT): One side to Pin 6, other side to GND
 * Button 2 (RIGHT): One side to Pin 7, other side to GND
 * Note: Internal pull-up resistors are enabled in code, so buttons read LOW when pressed
 */

#include <LiquidCrystal.h>
#include <stdlib.h>

#define GRAPHIC_WIDTH 16
#define GRAPHIC_HEIGHT 4
#define BUTTON_LEFT 6
#define BUTTON_RIGHT 7
#define DEBOUNCE_DONE 0xFFFFFFFF
#define DEBOUNCE_DURATION 20

#define GRAPHIC_ITEM_NONE 0
#define GRAPHIC_ITEM_A 1
#define GRAPHIC_ITEM_B 2

#define SNAKE_LEFT 0
#define SNAKE_UP 1
#define SNAKE_RIGHT 2
#define SNAKE_DOWN 3

#define GAME_MENU 0
#define GAME_PLAY 1
#define GAME_LOSE 2
#define GAME_WIN 3

// Initialize LCD: RS=12, E=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte block[3] = {B01110,B01110,B01110};
byte apple[3] = {B00100,B01010,B00100};

unsigned long debounceCounterButtonLeft = 0;
unsigned long debounceCounterButtonRight = 0;

struct Pos {
  uint8_t x;
  uint8_t y;
};

struct Pos snakePosHistory[64]; 
size_t snakeLength = 0;
int snakeDirection;
struct Pos applePos;
unsigned long lastGameUpdateTick = 0;
unsigned long gameUpdateInterval = 1000;
bool thisFrameControlUpdated = false;
int gameState;
uint8_t graphicRam[4][4];

bool debounce_activate_edge(unsigned long* debounceStart){
  if(*debounceStart == DEBOUNCE_DONE){
    return false;
  }else if(*debounceStart == 0){
    *debounceStart = millis();
  }else if(millis()-*debounceStart>DEBOUNCE_DURATION){
    *debounceStart = DEBOUNCE_DONE;
    return true;
  }
  return false;
}

void debounce_deactivate(unsigned long* debounceStart){
  *debounceStart = 0;
}

void graphic_generate_characters(){
  for (int i=0; i<8; i++) {
    byte glyph[8];
    int upperIcon = (i+1)/3;
    int lowerIcon = (i+1)%3;
    memset(glyph, 0, 8);
    if(upperIcon==1) memcpy(&glyph[0], &block[0], 3);
    else if(upperIcon==2) memcpy(&glyph[0], &apple[0], 3);
    if(lowerIcon==1) memcpy(&glyph[4], &block[0], 3);
    else if(lowerIcon==2) memcpy(&glyph[4], &apple[0], 3);
    lcd.createChar(i, glyph);
  }
}

void graphic_clear(){
  memset(graphicRam, 0, sizeof(graphicRam));
}

void graphic_add_item(uint8_t x, uint8_t y, uint8_t item) {
  if(x < 16 && y < 4) {
    graphicRam[x/4][y] |= item * (1 << ((x%4)*2));
  }
}

void graphic_flush(){
  lcd.clear();
  for(int x=0; x<16; x++){
    for(int y=0; y<2; y++){
      uint8_t upperItem = (graphicRam[x/4][y*2] >> ((x%4)*2)) & 0x3;
      uint8_t lowerItem = (graphicRam[x/4][y*2+1] >> ((x%4)*2)) & 0x3;
      if(upperItem>=3) upperItem = 2;
      if(lowerItem>=3) lowerItem = 2;
      lcd.setCursor(x, y);
      if(upperItem==0 && lowerItem==0) 
        lcd.write(' ');
      else 
        lcd.write(byte(upperItem*3+lowerItem-1));
    }
  }
}

void game_new_apple_pos(){
  bool validApple = true;
  do{
    applePos.x = rand() % GRAPHIC_WIDTH;
    applePos.y = rand() % GRAPHIC_HEIGHT;
    validApple = true;
    for(int i=0; i<snakeLength; i++){
      if(applePos.x==snakePosHistory[i].x && applePos.y==snakePosHistory[i].y){
        validApple = false;
        break;
      }
    }
  } while(!validApple);
}

void game_init(){
  randomSeed(micros());
  gameUpdateInterval = 500;
  gameState = GAME_PLAY;
  snakePosHistory[0].x=3; snakePosHistory[0].y=1;
  snakePosHistory[1].x=2; snakePosHistory[1].y=1;
  snakePosHistory[2].x=1; snakePosHistory[2].y=1;
  snakePosHistory[3].x=0; snakePosHistory[3].y=1;
  snakeLength = 4;
  snakeDirection = SNAKE_RIGHT;
  game_new_apple_pos();
  thisFrameControlUpdated = false;
}

void game_calculate_logic() {
  if(gameState != GAME_PLAY)
    return;
  
  for(int i=snakeLength; i>=1; i--){ 
    snakePosHistory[i] = snakePosHistory[i-1];
  }
  snakePosHistory[0] = snakePosHistory[1];
  
  if(snakeDirection==SNAKE_LEFT) snakePosHistory[0].x--;
  else if(snakeDirection==SNAKE_UP) snakePosHistory[0].y--;
  else if(snakeDirection==SNAKE_RIGHT) snakePosHistory[0].x++;
  else if(snakeDirection==SNAKE_DOWN) snakePosHistory[0].y++;
  
  if(snakePosHistory[0].x >= GRAPHIC_WIDTH || snakePosHistory[0].y >= GRAPHIC_HEIGHT){
    gameState = GAME_LOSE;
    return;
  }

  for(int i=1; i<snakeLength; i++){
    if(snakePosHistory[0].x==snakePosHistory[i].x && snakePosHistory[0].y==snakePosHistory[i].y){
      gameState = GAME_LOSE;
      return;
    }
  }

  if(snakePosHistory[0].x==applePos.x && snakePosHistory[0].y==applePos.y){
    snakeLength++;
    if(gameUpdateInterval > 150)
      gameUpdateInterval = gameUpdateInterval * 9 / 10;
    if(snakeLength >= 64)
      gameState = GAME_WIN;
    else
      game_new_apple_pos();
  }
}

void game_calculate_display() {
  graphic_clear();
  
  if(gameState == GAME_LOSE){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Game Over!");
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(snakeLength);
  }
  else if(gameState == GAME_WIN){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  You Won!");
    lcd.setCursor(0, 1);
    lcd.print("Perfect Score!");
  }
  else if(gameState == GAME_PLAY){
    for(int i=0; i<snakeLength; i++)
      graphic_add_item(snakePosHistory[i].x, snakePosHistory[i].y, GRAPHIC_ITEM_A);
    graphic_add_item(applePos.x, applePos.y, GRAPHIC_ITEM_B);
    graphic_flush();
  }
  else if(gameState == GAME_MENU){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Snake Game");
    lcd.setCursor(0, 1);
    lcd.print("Press to Start");
  }
}

void setup() {
  lcd.begin(16, 2);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);  // Enable internal pull-up
  pinMode(BUTTON_RIGHT, INPUT_PULLUP); // Enable internal pull-up
  graphic_generate_characters();
  gameState = GAME_MENU;
  game_calculate_display();
}

void loop() {
  // Left button - turn counter-clockwise (LOW when pressed with pull-up)
  if(digitalRead(BUTTON_LEFT) == LOW){
    if(debounce_activate_edge(&debounceCounterButtonLeft) && !thisFrameControlUpdated){
      if(gameState == GAME_PLAY){
        if(snakeDirection == SNAKE_LEFT) snakeDirection = SNAKE_DOWN;
        else if(snakeDirection == SNAKE_UP) snakeDirection = SNAKE_LEFT;
        else if(snakeDirection == SNAKE_RIGHT) snakeDirection = SNAKE_UP;
        else if(snakeDirection == SNAKE_DOWN) snakeDirection = SNAKE_RIGHT;
        thisFrameControlUpdated = true;
      }
      else{
        game_init();
      }
    }
  }
  else{
    debounce_deactivate(&debounceCounterButtonLeft);
  }
  
  // Right button - turn clockwise (LOW when pressed with pull-up)
  if(digitalRead(BUTTON_RIGHT) == LOW){
    if(debounce_activate_edge(&debounceCounterButtonRight) && !thisFrameControlUpdated){
      if(gameState == GAME_PLAY){
        if(snakeDirection == SNAKE_LEFT) snakeDirection = SNAKE_UP;
        else if(snakeDirection == SNAKE_UP) snakeDirection = SNAKE_RIGHT;
        else if(snakeDirection == SNAKE_RIGHT) snakeDirection = SNAKE_DOWN;
        else if(snakeDirection == SNAKE_DOWN) snakeDirection = SNAKE_LEFT;
        thisFrameControlUpdated = true;
      }
      else{
        game_init();
      }
    }
  }
  else{
    debounce_deactivate(&debounceCounterButtonRight);
  }
  
  if(millis() - lastGameUpdateTick > gameUpdateInterval){
    game_calculate_logic();
    game_calculate_display();
    lastGameUpdateTick = millis();
    thisFrameControlUpdated = false;
  }
}
