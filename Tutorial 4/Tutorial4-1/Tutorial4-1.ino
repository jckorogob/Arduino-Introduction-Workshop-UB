#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
 lcd.begin(16, 2); 
}

void loop()
{
  lcd.setCursor(1,0);          
  lcd.print("ABCDEFGHIJKLMP"); 
  lcd.setCursor(2,1);           
  lcd.print("TPMM");    
  delay(4000);
  lcd.clear();
  delay(5000);
}