
#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT D6
#define CLK  D7
HX711 scale(DOUT, CLK);

#include<Servo.h>
int servoPin= D0;
Servo servo;
int servoAngle=0;

const int gasPin = A0;
#define TRIGGER D2
#define ECHO    D3

#define TRIGGER2 D4
#define ECHO2    D5

#define PI 3.14
#define r 5
#define h 16
//const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin

void setup()
{
  Serial.begin(9600); 
 pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  servo.attach(servoPin);
  pinMode(D1,HIGH);
  

  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); 
 
}

void loop(){
  float  reading = analogRead(gasPin);
  long duration, distance,duration2, distance2;
  float volume,volume2;
  /*Begin Ultrasonic 1 */
  
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  volume = PI*r*r*(h-distance );
  Serial.print("Toordal : ");
  Serial.println(volume);
    delay(1000);
/*End of ultrasonic 1 */
    
/* Begin Ultrasonic 2 
   digitalWrite(TRIGGER2, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER2, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER2, LOW);
  duration2= pulseIn(ECHO2, HIGH);
  distance2 = (duration2/2) / 29.1;
  volume2 = PI*r*r*(h-distance2 );
  Serial.print("Sugar : ");
  Serial.println(volume2);
    delay(1000);*/
/*End of ultrasonic 2 */ 

/*Begin Gas sensor */
  if(reading>170 && reading<250)
  {
   digitalWrite(D1,HIGH);
   delay(500);
   digitalWrite(D1,LOW);
   delay(500);
  }
  
  
    else if(reading>250)
    {
      Serial.print(reading);
      Serial.print("\t");
      Serial.println("Gas leaking");
      servo.write(90);
      delay(1000);
      for(servoAngle=0;servoAngle<180;servoAngle=servoAngle+10)
      {
        servo.write(servoAngle);
        delay(50);
      }
      for(servoAngle=180;servoAngle>0;servoAngle=servoAngle-10)
      {
      servo.write(servoAngle);
      delay(50);
      }
    }
/*End Gas sensor */

/*Begin Loadcell */ 
  Serial.println("HX711 scale demo");
  Serial.print(" Loadcell Reading: ");
  Serial.print((scale.get_units()*23.5985)+400, 1); //scale.get_units() returns a float
  Serial.println(" grams"); 

/*End Loadcell  */
  
  delay(2000); // Print value every 1 sec.
  
    } 
