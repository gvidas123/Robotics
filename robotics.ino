#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <SPI.h>

int pinCS  = 10;
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 1;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
const int ledPin = 9;    // the number of the LED pin
const int buttonPin = 3;
const int buttonPin2 = 5;
volatile byte button = LOW;
int Npreses = 0;
int lol = 0;
bool write = false;
volatile byte buttonState2 = LOW;
volatile byte buttonState1 = LOW;
int x = numberOfHorizontalDisplays * 8 / 2;
int y = numberOfVerticalDisplays * 0 ;
int raindrops[8] = {0,1,0,1,1,0,1,0};
int raindropsy[8] = {8,8,8,8,8,8,8,8};
int W[8][8]{
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,1,0,1,0},
  {0,0,1,0,1,0,1,0},4
  {0,0,0,1,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}

};
int wait = 400;
bool trueend = false;
void setup() {
  float f = 0.00f;
  matrix.setIntensity(10);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  Npreses = EEPROM.read(0);
  lol = Npreses;
}

void loop() {
  digitalWrite(ledPin, button);
  buttonState2 = digitalRead(buttonPin2);
  buttonState1 = digitalRead(buttonPin);
  if (buttonState1 == HIGH) {
    button = !button;
  }
  if (buttonState2 == HIGH) {
    button = !button;
  }
  if (buttonState1  == HIGH && x < 7) {
    x++;
    matrix.drawPixel(x-1, y, LOW);
  }
  if (buttonState2 == HIGH && x > 0){
    x--;
    matrix.drawPixel(x+1, y, LOW);
  }
  matrix.drawPixel(x,y,HIGH);
  matrix.write();
  
  for (int i = 0; i < 8; i++){
    
    if (raindrops[i] == 1) {
      matrix.write();
      raindropsy[i] -=1;
      matrix.drawPixel(i,raindropsy[i],HIGH);
      matrix.drawPixel(i, raindropsy[i]+1, LOW);
      matrix.write();
      if (raindropsy[i] == -2) {
        raindrops[i] = 0;
        raindropsy[i] = 8;
        
      }
    }
  }
if (wait == 50 || trueend == true) {

  for (int i = 0; i < 8;i++){
    for (int x = 0; x < 8;x++){
      if (W[i][x] == 1) {
        matrix.drawPixel(i,x,HIGH);
      }
    }
  }
  matrix.write();
  trueend = true ;
}
  bool ended = true;
  for (int i = 0; i < 8; i++){
    if (raindrops[i] == 1) {
      ended = false;
    }
  }
if (ended == true && trueend == false ) { 
  for(int x = 0; x < 8; x++) {
    int random = rand() % 8;
    raindrops[random] = 1;
  }
  wait -= 50;
}
  delay(wait);  
}


