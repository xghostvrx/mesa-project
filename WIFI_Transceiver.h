#ifndef WIFI_Transceiver_h
#define WIFI_Transceiver_h
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <FS.h>   // Include the SPIFFS library

extern void WIFI_initialize();
extern void WIFI_webserver(void);

#endif