#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
  
char ssid[] = "hackathon10";    
char pass[] = "abcd@12345";   
WiFiClient  client;

unsigned long myChannelNumber = 289680;
const char * myReadAPIKey = "DOYUIQ4T9SXLW63R";

void setup() {
  pinMode(D2,OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
}

void loop() {
  float data = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
  if(data>600)
  {

  digitalWrite(D2,HIGH);
  }
  else
  digitalWrite(D2,LOW);
  Serial.print("Latest data is: "); 
  Serial.println(data);
  
  delay(1000);
}
