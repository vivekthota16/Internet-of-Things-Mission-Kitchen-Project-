#include "ThingSpeak.h"
//#include <ESP8266WiFi.h>
#include <WiFi.h>

char ssid[] = "Vicky";    //  your network SSID (name) 
char pass[] = " ";   // your network password

WiFiClient  client;    

unsigned long myChannelNumber = 290437;
const char * myWriteAPIKey = "HSXSWWJ4WWUFB6WV";

void setup() {
 
pinMode(7,OUTPUT);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);  
  Serial.begin(9600);
digitalWrite(7,HIGH);
}


void loop() {
float  d=analogRead(A0);
float voltage = d * (5 / 1023.00);
  ThingSpeak.writeField(myChannelNumber, 1, voltage, myWriteAPIKey);
  Serial.println(voltage);
  delay(1000);
  
}

  


