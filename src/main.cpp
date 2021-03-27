#include <Arduino.h>

#define clickPin 2

int awaitTime = 1000;
int clicks;
bool firstClick = false;
int CPM;
float uSv;
float roentgen;
float MAXIMUM_TOLERANCE = 7.0;

void onClick();
void displayToPlotter();
void toSievert();
void wait();
void redAlert();
void showCPM();

unsigned long previousMillis;
unsigned long currentMillis = millis();

void setup() {
  attachInterrupt(digitalPinToInterrupt(clickPin), onClick, FALLING);
  digitalWrite(clickPin, LOW);
  Serial.begin(9600);
  Serial.println("Awaiting random click from Geiger on Input pin...");
  while (firstClick == false){
    Serial.print("...");
  }
  //TEST
  Serial.println();
  Serial.print("Success after:");
  Serial.println(String(millis()) + "ms");
  Serial.println();
}

void loop() {
  previousMillis = currentMillis;
  while (currentMillis - previousMillis <= 60000){
    currentMillis = millis();
  }
  CPM = clicks;
  clicks = 0;
  Serial.println("-------------------RESULTS OF THE LAST MINUTE-------------------");
  showCPM();
  toSievert();
  Serial.println("----------------------------------------------------------------");
}

void onClick(){
  firstClick = true;
  clicks++;
}

void toSievert(){
  uSv = CPM * 0.00812037037037;
  Serial.println();
  Serial.print("Current uSv/h: ");
  Serial.println(uSv);
  Serial.println();
  if (uSv >= MAXIMUM_TOLERANCE){
    redAlert();
  }
}

void redAlert(){
  Serial.println();
  Serial.print("The highest tolerance of, ");
  Serial.print(MAXIMUM_TOLERANCE);
  Serial.print(" uSv/h has been reached!");
  Serial.println();
  Serial.println("LEAVE THE AREA IMMEDIATELY!");
}

void showCPM(){
  Serial.println();
  Serial.print("Current CPM: ");
  Serial.println(CPM);
  Serial.println();
}