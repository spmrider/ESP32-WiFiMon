#ifndef _MAIN_H
#define _MAIN_H

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <time.h>

#include "mqttconf.h"

// Enable/Disable Webservice
#define WEBSERVER false

// to be tuned
#define STACK_SIZE 8192

// Time Servers
#define NTP1 "0.de.pool.ntp.org"
#define NTP2 "1.de.pool.ntp.org"

// Olimex ESP32 PoE Etehrnet
#define ETH_CLK_MODE ETH_CLOCK_GPIO17_OUT
#define ETH_PHY_POWER 12

#include "ETH.h"

// Web Server
#if(WEBSERVER)
#include <ESP32WebServer.h>
#define sitewidth  1024  // Adjust site page width in pixels as required
#endif

// General Clients
#include <WiFiClientSecure.h>
#include <ESPmDNS.h>

// Adafruit MQTT Library
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

// Scan wait time (seconds)
#define APSCAN_FREQ 2

#ifndef _GLOBALS_CPP
#include "globals.h"
#endif //_GLOBALS_CPP

#endif // _MAIN_H
