

#include <NewPing.h>
int Forward_L = 8;
int Forward_R = 12; 
int Stat_L = 9;
int Stat_R = 10;
int Back_L = 7;
int Back_R = 11;

int LEFT_FEEDBACK = 2; // Pin numbers on Rover
int RIGHT_FEEDBACK = 3;

int leftcounter = 0; // initiate counter to zero for start
int rightcounter = 0; // counter could always be reset

int leftspeed = 125;
int rightspeed = 125;
int newSpeed = 125;
#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
  pinMode(Forward_L,OUTPUT);
  pinMode(Stat_L,OUTPUT);
  pinMode(Back_L,OUTPUT);
  pinMode(Forward_R,OUTPUT);
  pinMode(Stat_R,OUTPUT);
  pinMode(Back_R,OUTPUT);
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  //pinMode(ECHO_PIN,INPUT_PULLUP);
  int distance = sonar.ping_cm();

}



void loop() {
  // put your main code here, to run repeatedly:

}
void forwards(){
  analogWrite(Stat_L, leftspeed); // enable motors on
  analogWrite(Stat_R, rightspeed);

  
  digitalWrite(Forward_L, HIGH); // forward motors on
  digitalWrite(Forward_R, HIGH);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);
  Serial.println("forwards");
}

void backwards(){
  analogWrite(Stat_L,leftspeed); // enable motors on
  analogWrite(Stat_R,rightspeed);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, HIGH);  // reverse motors on
  digitalWrite(Back_R, HIGH);
}
void hardstop(){

  digitalWrite(Stat_L,HIGH); // enable motors on
  digitalWrite(Stat_R,HIGH);

  digitalWrite(Forward_L,HIGH); // forward motors on
  digitalWrite(Forward_R,HIGH);

  digitalWrite(Back_L, HIGH);  // reverse motors on
  digitalWrite(Back_R, HIGH);
  
}
void brake(){
  
  digitalWrite(Stat_L,LOW); // enable motors off
  digitalWrite(Stat_R,LOW);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);
  
}

void leftturn(){
  analogWrite(Stat_L, leftspeed); // enable motors on
  analogWrite(Stat_R, rightspeed);

  digitalWrite(Forward_L, LOW); // forward motors on
  digitalWrite(Forward_R, HIGH);

  digitalWrite(Back_L, HIGH);  // reverse motors off
  digitalWrite(Back_R, LOW);
  Serial.println("rightturn");
}
