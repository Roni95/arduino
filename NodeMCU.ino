#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

#define REED_SWITCH 5 //D1
#define LED D2

const char* serverName = "https://manhole.test71.xyz/api/manhole/1";

int status = WL_IDLE_STATUS; //not required.
int Manhole_No = 1;
const char* ssid = "My-WiFi";
const char* password = "12341234";
int doorClosed = 1;
WiFiClient wifiClient;

void setup() {
  pinMode(REED_SWITCH, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  setupWifi();
}
void setupWifi()
{
   WiFi.mode(WIFI_STA);
   status = WiFi.begin(ssid, password);    
   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);  
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
   }
   Serial.println("Connected to wifi");
   Serial.println(WiFi.localIP());
}

void loop() {
    if (WiFi.status() != WL_CONNECTED)
    {
     setupWifi();
    }
    HTTPClient http;   
    if ((digitalRead(REED_SWITCH) == LOW) && doorClosed == 0 )
    {
      Serial.println("DOOR OPEN!!");  
      doorClosed = 1;
      String response;
      StaticJsonDocument<200> buff;
      String jsonParams;
      buff["status"]=1;
      serializeJson(buff, jsonParams);
      Serial.println(jsonParams); 
      http.begin(wifiClient, "http://manhole.test71.xyz/api/manhole/1");
      http.addHeader("Content-Type", "application/json");
      //int result = http.PUT(jsonParams);
      //response = http.getString();
      //Serial.println(response);
      http.end();
    } 
    else if ((digitalRead(REED_SWITCH) == HIGH) && doorClosed == 1)
    {
      Serial.println("DOOR CLOSED!!");  
      doorClosed = 0;
      String response;
      StaticJsonDocument<200> buff;
      String jsonParams;
      buff["status"]=0;
      serializeJson(buff, jsonParams);
      Serial.println(jsonParams); 
      http.begin(wifiClient, "http://manhole.test71.xyz/api/manhole/1");
      http.addHeader("Content-Type", "application/json");
      //int result = http.PUT(jsonParams);
      //response = http.getString();
      //Serial.println(response);
      http.end();
    }
    delay(1000);
}
