/*  PSX Controller Decoder Library (Psx.pde)
	Written by: Kevin Ahrendt June 22nd, 2008
	
	Controller protocol implemented using Andrew J McCubbin's analysis.
	http://www.gamesx.com/controldata/psxcont/psxcont.htm
	
	Shift command is based on tutorial examples for ShiftIn and ShiftOut
	functions both written by Carlyn Maw and Tom Igoe
	http://www.arduino.cc/en/Tutorial/ShiftIn
	http://www.arduino.cc/en/Tutorial/ShiftOut

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Psx.h>  // Includes the Psx Library 
#include <Servo.h>
// Any pins can be used since it is done in software
#define dataPin 12
#define cmndPin 11
#define attPin 10
#define clockPin 13
#define cepat 200
#define lambat 100
#

#define LEDPin A5
Servo myservo;

Psx Psx;                                                  // Initializes the library

unsigned int data = 0;                                    // data stores the controller response

void setup()
{
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);  // Defines what each pin is used
 pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);                                                         // (Data Pin #, Cmnd Pin #, Att Pin #, Clk Pin #, Delay)
  myservo.attach(9);                                                       // Delay measures how long the clock remains at each state,
                                                          // measured in microseconds.
                                                          // too small delay may not work (under 5)
  pinMode(LEDPin, OUTPUT);                                // Establishes LEDPin as an output so the LED can be seen
  Serial.begin(9600);
}

void loop()
{
  data = Psx.read();                                      // Psx.read() initiates the PSX controller and returns
                                                          // the button data
  Serial.println(data);                                   // Display the returned numeric value
  if (data == 8)                                       // If the data anded with a button's hex value is true,
  {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  analogWrite(5, lambat);
  analogWrite(6, lambat);                           // If button is pressed, turn on the LED
  }

  if (data == 0)                                       // If the data anded with a button's hex value is true,
  {
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  analogWrite(5, 0);
  analogWrite(6, 0);                           // If button is pressed, turn on the LED
  }
  
  if (data == 2)                                       // If the data anded with a button's hex value is true,
  {
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(5, lambat);
  analogWrite(6, lambat);                           // If button is pressed, turn on the LED
  }  

  if (data == 1)                                       // If the data anded with a button's hex value is true,
  {
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  analogWrite(5, lambat);
  analogWrite(6, lambat);                           // If button is pressed, turn on the LED
  }
  
  if (data == 4)                                       // If the data anded with a button's hex value is true,
  {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(5, lambat);
  analogWrite(6, lambat);                           // If button is pressed, turn on the LED
  }
  
  if (data == 2048) {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  analogWrite(5, cepat);
  analogWrite(6, cepat);
  }
  
  if (data == 512) {
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(5, cepat);
  analogWrite(6, cepat);
  }
  
  if (data == 1024) {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(5, cepat);
  analogWrite(6, cepat);
  }
  
  if (data == 256) {
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  analogWrite(5, cepat);
  analogWrite(6, cepat);
  }

  if (data == 8192){ 
 myservo.write(5);
  }
  
   if (data == 4096){
 myservo.write(5);
 delay(100);
   }
   
  delay(20);

}
