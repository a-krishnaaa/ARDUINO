#include<Servo.h>
Servo servoMain;    //To create servo object
int trigpin = 9;    //Trigger pin of Ultrasonic sensor
int echopin = 8;    //Echo pin of Ultrasonic sensor
int distance;
float duration;
float cm;
void setup(){
servoMain.attach(7); //
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}
void loop(){
													     
digitalWrite(trigpin, LOW);
delay(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
cm = (duration/58.82);
distance = cm;
if(distance<70)
{ 
        servoMain.write(90);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);                     //To turn ON all five status LEDs 
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
       	digitalWrite(6,LOW);
         delay(1000);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(1000);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(1000);
         digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(1000);
         digitalWrite(2,LOW);
        digitalWrite(3,LOW);
       																											     
 	      digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(1000);
    }
    else { 
        servoMain.write(70); 
        servoMain.write(50);
        servoMain.write(30);
        servoMain.write(0);
        delay(20);
          digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
        delay(220);
        
          digitalWrite(11,LOW);
           digitalWrite(12,HIGH);
           delay(220);
          }
}
