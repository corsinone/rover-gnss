// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <WiFi.h>
#include "NTRIPClient.h"
#include <HardwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TinyGPSPlus.h>
#include <PubSubClient.h>
#include <BluetoothSerial.h>
#include <Preferences.h>

// Définition du niveau de log
#define LOG_LEVEL_NONE  0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_INFO  3
#define LOG_LEVEL_DEBUG 4

#define LOG_LEVEL LOG_LEVEL_DEBUG

// Pinouts
#define PIN_TX 26
#define PIN_RX 27 
#define POWER_PIN 25
#define ONE_WIRE_BUS 0

// WiFi configuration
extern char ssid[64];
extern char password[64];

// MQTT configuration
extern char mqtt_server[64];
extern int mqtt_port;
extern char mqtt_output[64];
extern char mqtt_input[64];
extern char mqtt_log[64];
extern char mqtt_user[64];
extern char mqtt_password[64];
extern const char mqtt_UUID[];
extern int publish_freq;

// NTRIP configuration
extern char host[64];
extern int httpPort;
extern char mntpnt[32];
extern char user[32];
extern char passwd[32];

// Network configuration
extern IPAddress server;
extern int port;
extern const char* udpAddress;
extern const int udpPort;
extern int trans;

// Timing intervals
extern const unsigned long wifiReconnectInterval;
extern const unsigned long mqttReconnectInterval;
extern const unsigned long ntripReconnectInterval;

// Global variables
extern WiFiClient espClient;
extern PubSubClient client;
extern TinyGPSPlus gps;
extern NTRIPClient ntrip_c;
extern WiFiUDP udp;
extern BluetoothSerial SerialBT;
extern HardwareSerial MySerial;
extern OneWire oneWire;
extern DallasTemperature sensors;
extern DeviceAddress Thermometer;
extern int deviceCount;
extern float temp;
extern unsigned long lastWifiReconnectAttempt;
extern unsigned long lastMqttReconnectAttempt;
extern unsigned long lastNtripReconnectAttempt;
extern bool ntripConnected;
extern TaskHandle_t nmeaTaskHandle;
extern SemaphoreHandle_t xSemaphore;
extern TinyGPSCustom gnssGeoidElv;
extern TinyGPSCustom gnssFixMode;
extern TinyGPSCustom gnssPDOP;
extern TinyGPSCustom gnssHDOP;
//Web
extern Preferences preferences;
void loadPreferences();
void savePreferences();
void resetPreferences();
void requestSourceTable(); 
void requestMountPointRawData();
//Wifi AP
extern bool isAPMode; 
extern unsigned long lastAPCheckTime; // Ajoutez cette ligne
extern const unsigned long apCheckInterval;

#endif // CONFIG_H
