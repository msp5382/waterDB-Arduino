
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;


void setup()
{
  Serial.begin(9600);

  Serial.println();

  WiFi.begin("******", "******");   //WiFi connection

  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion

    delay(500);
    Serial.println("Waiting for connection");

  }
}
void loop()
{
  String dataString = "Hello Water"
  sendToWater(dataString);
  Serial.println(dataString);
  delay(1000);
}

void sendToWater(String data) {
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;
    http.begin("http://*****WATERDB-IP******/push/");
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST("{\"path\":\"fifa\",\"content\":\"" + data + "\"}");
    Serial.print("Save at WaterDB with code : ");
    Serial.println(httpCode);
  }
}