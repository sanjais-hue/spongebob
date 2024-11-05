#include <Servo.h>
Servo hand_1,hand_2,eye;

#include <SoftwareSerial.h>
#include<JQ6500_Serial.h>
SoftwareSerial mySerial(6,7); 
JQ6500_Serial mp3(mySerial);

#define hand_1_pin 10 
#define hand_2_pin 11
#define eye_pin    9
unsigned long prevtime_1=0;


int handPos1 = 0;     // Position for first hand servo
int handPos2 = 180;   // Position for second hand servo (reverse)
int handSpeed = 1;    // Speed of the hand movement


int eyePos = 0;       // Position for eye servo
int eyeDirection = 1; // 1 for moving from 0 to 90, -1 for moving back



const long interval = 100;               // Interval for updating servo positions

unsigned long currtime;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  mp3.reset();
  mp3.setVolume(50);
  mp3.setLoopMode(MP3_LOOP_NONE);
  mp3.play();
  mp3.playFileByIndexNumber(1);
  delay(1000);
  mp3.reset();
  hand_1.attach(hand_1_pin);
  hand_2.attach(hand_2_pin);
  eye.attach(eye_pin);
  hand_1.write(90);
  hand_2.write(90);
  eye.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  fun1();
  mp3.play();
  mp3.playFileByIndexNumber(1);
  fun2();
  mp3.play();
  mp3.playFileByIndexNumber(1);
  fun3();
}
void fun1(){
  for (int i=90; i<180 ;i++){
    hand_1.write(i);
    hand_2.write(i);
    delay(100);
  }
  
  for (int i=180; i>0 ;i--){
    hand_1.write(i);
    hand_2.write(i);
    delay(100);
  }
  for (int i=0; i<90 ;i++){
    hand_1.write(i);
    hand_2.write(i);
    delay(100);
  }
}
void fun2(){
  for (int i=90; i<180 ;i++){
    hand_1.write(i);
    hand_2.write(i);
    eye.write(i);
    delay(100);
  }
  
  for (int i=180; i>0 ;i--){
    hand_1.write(i);
    hand_2.write(i);
    eye.write(i);
    delay(100);
  }
  for (int i=0; i<90 ;i++){
    hand_1.write(i);
    hand_2.write(i);
    eye.write(i);
    delay(100);
  }
}
void fun3(){
  hand_1.write(90);
  hand_2.write(90);
  mp3.play();
  mp3.playFileByIndexNumber(1);
  for (int i=90; i<180 ;i++){
    eye.write(i);
    delay(100);
  }
  mp3.play();
  mp3.playFileByIndexNumber(1);
  for (int i=180; i>0 ;i--){
    eye.write(i);
    delay(100);
  }
  mp3.play();
  mp3.playFileByIndexNumber(1);
  for (int i=0; i<90 ;i++){
    eye.write(i);
    delay(100);
  }
  mp3.play();
  mp3.playFileByIndexNumber(1);
}
