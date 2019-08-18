#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

int S = 59; // count seconds 
int M = 59; // count minutes
int H = 23; // count hours
int D = 20;
//initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE); // pins connected to LCD
 
void setup()
{
 lcd.begin(16,2);//set up the LCD's number of columns and rows

} 
void loop()
{ 


 lcd.setCursor(6,0);
 lcd.print("Hari Lagi");
 lcd.setCursor(6,1);
 lcd.print(":");
 lcd.setCursor(9,1);
 lcd.print(":");

 if (D<0)
 {
 D=20;
 H=23;
 M=59;
 S=59;
 } 
 
 
 S = EEPROM.read(60);
 M = EEPROM.read(61);
 H = EEPROM.read(0);
 D = EEPROM.read(1);
 
 S--;
 delay(0.001);

 if(S<0)
 {
 M--;
 S=59;
 }
 
 if(M<0)
 {
 H--;
 M=59;
 EEPROM.write(0,H);
 }
 
 if(H<0)
 {
 D--;
 H=23;
 EEPROM.write(1, D);
 }
 
 EEPROM.write(60, S);
 EEPROM.write(61, M);
 
 if(M>9)
 {
 lcd.setCursor(7,1);
 lcd.print(M);
 }
 else
 {
 lcd.setCursor(7,1);
 lcd.print("0"); 
 lcd.setCursor(8,1);
 lcd.print(M);
 lcd.setCursor(9,1);
 lcd.print(":");
 }
  
 if(S>9)
 {
 lcd.setCursor(10,1);
 lcd.print(S);
 }
 else
 {
 lcd.setCursor(10,1);
 lcd.print("0"); 
 lcd.setCursor(11,1);
 lcd.print(S);
 lcd.setCursor(12,1);
 lcd.print(" ");
 }
  
 if(H>9)
 {
 lcd.setCursor(4,1);
 lcd.print (H);
 }
 else
 {
 lcd.setCursor(4,1);
 lcd.print("0"); 
 lcd.setCursor(5,1);
 lcd.print(H);
 lcd.setCursor(6,1);
 lcd.print(":");
 }
  if(D>9)
 {
 lcd.setCursor(3,0);
 lcd.print (D);
 }
 else
 {
 lcd.setCursor(4,0);
 lcd.print("0"); 
 lcd.setCursor(5,0);
 lcd.print(D);
 }
}


