// Hydroponic System (Cost Effective Plant Growing Solution) - MESA National Submission
// THMS MESA Team: Rojina Khatri, Nadira Mitchell, Moses Osuna, George Testo (metro1102@gmail.com)
// Prototyping Started: Feburary 15, 2019

#include <Arduino.h>
#include "PH_Sensor.h"
/*#include "SD_Reader.h"
#include "WIFI_Transceiver.h"*/

int countingLoop;
int relayIN1 = 6;
int relayIN2 = 7;
int relayIN3 = 8;
int relayIN4 = 9;
int FLOAT_SENSOR1 = 2;
int FLOAT_SENSOR2 = 3;

void setup() {
  // Initialize relay pins as outputs:
  pinMode(relayIN1, OUTPUT);
  pinMode(relayIN2, OUTPUT);
  pinMode(relayIN3, OUTPUT);
  pinMode(relayIN4, OUTPUT);

  // Initialize floatswitch pins as inputs:
  pinMode(FLOAT_SENSOR1, INPUT_PULLUP);
  pinMode(FLOAT_SENSOR2, INPUT_PULLUP);

  // Disables all relay circuits:
  digitalWrite(relayIN1, HIGH);
  digitalWrite(relayIN2, HIGH);
  digitalWrite(relayIN3, HIGH);
  digitalWrite(relayIN4, HIGH);

  // Initialize serial communication:
  Serial.begin(9600);
  delay(10);
  Serial.println("Hydroponic System Core Initiated!");
  Serial.println("Initializing system components:");

  // Initializes system components:
  PH_initialize();
  /*SD_initialize();
  WIFI_initialize();*/
}

void loop() {
  // Check Floats:
  if(digitalRead(FLOAT_SENSOR1) == HIGH && digitalRead(FLOAT_SENSOR2) == LOW) {  // if both false
   digitalWrite(relayIN3, LOW);
   digitalWrite(relayIN4, LOW);
  }
  else {  // if either true
    // Turn off system & wait until loop is over:
    countingLoop = 0;
    digitalWrite(relayIN3, HIGH);
    digitalWrite(relayIN4, HIGH);
    while (countingLoop < 10) {
      functions();
      delay(1000*5);
      countingLoop = countingLoop + 1;
    }
    return;
  }

} 

void functions()  {
  // Establish pH:
  PH_valuecalc();
  
  if (pHValue < 6) {  // if pH is low, dose 2ml of pH UP    
    digitalWrite(relayIN1, LOW);
    delay(1000*3);
    digitalWrite(relayIN1, HIGH);
  }
  else {  // otherwise, do nothing
    digitalWrite(relayIN1, HIGH); 
  }

  if (pHValue > 7) {  // if pH is high, dose 2ml of pH DOWN            
    digitalWrite(relayIN2, LOW);
    delay(1000*3);
    digitalWrite(relayIN2, HIGH);
  }
  else { // otherwise, do nothing
    digitalWrite(relayIN2, HIGH);  
  }
  
  /*// Save pH Data on an SD Card:
  SD_savingdata();

  // Listen for HTTP requests from clients:
  WIFI_webserver();*/
}
