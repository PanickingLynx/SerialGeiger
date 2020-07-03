#include <Arduino.h>

#define clickPin 2

int awaitTime = 1000;
int clicks;
bool firstClick = false;
int CPM;
float uSv;

void onClick();
void displayToPlotter();
void toSievert();
void wait();
unsigned long previousMillis = millis();
unsigned long currentMillis = millis();

void setup() {

  attachInterrupt(digitalPinToInterrupt(clickPin), onClick, FALLING);
  digitalWrite(clickPin, LOW);
  Serial.begin(9600);
  Serial.println("Awaiting random click from Geiger on Input pin...");
  while (firstClick == false){
    Serial.print("...");
  }
  Serial.println("Success after:");
  Serial.print(millis() + "ms");
}

void loop() {
  currentMillis = millis();
  while (currentMillis - previousMillis <= 60000){
    //Do nothing because the interrupt handles the clicks.
  }
  CPM = clicks;
  clicks = 0;
  toSievert();
}

void onClick(){
  firstClick = true;
  clicks++;
}

void toSievert(){
  uSv = CPM * 0.00812037037037;
  Serial.print("Current uSv: ");
  Serial.println(uSv);
}