#include "PH_Sensor.h"
#include "SD_Reader.h"

unsigned long Time0 = 0; // A starting time reference, in millis

void SD_initialize()  {
  // Initialize the SD card:
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("Card failed, or not present.");
    while (1);
  }
  Serial.println("Card initialized.");
}

void SD_savingdata() {
  // Data preparation for file saving:
  String dataString = ""; // string for assembling the data to log:
  
  // Add Time tag:
  Time0 = millis();
  dataString += String(Time0);  dataString += ",";

  // Append the SEN0161 data to the string: 
  dataString += String(pHValue);  dataString += ",";
  dataString += String(voltage);  dataString += ",";
  
  // Open the file in append mode:
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // If the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
  // If the file does not open, prompt an error:
  else  {
    Serial.println("Error opening datalog.txt");
    return;
  }

}