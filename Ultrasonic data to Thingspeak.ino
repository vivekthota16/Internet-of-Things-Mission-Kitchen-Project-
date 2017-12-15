#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#define r1 6 //outer radius
#define r2 7 //inner radius
#define h1 3.5 //large circle height
#define h2 11 //small circle height
#define tv 2321.09
//#define  dsug 1.59
#define dsal 2.169
#define pi 3.1415
//#define TRIGGER_PIN1  D1
#define TRIGGER_PIN2  D3
//#define ECHO_PIN1     D0
#define ECHO_PIN2     D2
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
//NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
//NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
float v,d1,d2,wsal,wsug,density;



char ssid[] = "hackathon";    //  your network SSID (name) 
char pass[] = "pass@123";   // your network password

WiFiClient  client;    

unsigned long myChannelNumber = 290437;
const char * myWriteAPIKey = "HXXSSWWJ4WWUFB6WV";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);  
}



void loop() {
   long duration;
int distance;

// Clears the trigPin
digitalWrite(TRIGGER_PIN2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIGGER_PIN2, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_PIN2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHO_PIN2, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);


  // d1 = sonar1.ping_cm();
  d2 =distance ;
  ThingSpeak.writeField(myChannelNumber, 1, d1, myWriteAPIKey);
  delay(20000);
  
}
