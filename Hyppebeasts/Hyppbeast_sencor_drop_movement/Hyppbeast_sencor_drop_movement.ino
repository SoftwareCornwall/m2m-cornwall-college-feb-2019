int LME = 9;
int LMR = 7;
int LMF = 8;
int RME = 10;
int RMR = 11;
int RMF = 12;
int leftspeed = 205;
int rightspeed = 195;

const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; // initiate counter to zero for start 
volatile int rightcounter = 0; // counter could always be reset

#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200);
  pinMode(LME, OUTPUT);
  pinMode(RMR, OUTPUT);
  pinMode(RME, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMR, OUTPUT);
  pinMode(LME, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR,RISING);
     attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
 int distance = sonar.ping_cm();
}

void loop() {
 forwards();

  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  int distance = sonar.ping_cm();

  if (distance > 13){
 Stop(500);
 backwards();
 delay(500);
 left();
 delay(3750);
 backwards();
 delay(7000);
 Stop(500);
 left();
 delay(2000);

    Serial.println("Left counter ");
    Serial.print(leftcounter);

    Serial.println("Right counter ");
    Serial.print(rightcounter);

    if(leftcounter > rightcounter){
      Serial.print("Left bigger");
    }
    
    if(rightcounter > leftcounter){
      Serial.print("right bigger");
    }
  
  forwards();
  delay(1500);
  Stop(500);
 
  right();
  delay(1010);
  Stop(500);
  
  forwards();
  delay(1500);
  Stop(500);
 
  right();
  delay(1010);
  Stop(500);
  
  forwards();
  delay(1500);
  Stop(500);
 
  right();
  delay(1010);
  Stop(500);
  
  forwards();
  delay(1500);
  Stop(500);
  
  left();
  delay(900);
  Stop(1000); 
 
  forwards();
  delay(1500);
  Stop(500);
 
  left();
  delay(900);
  Stop(500);
  
  forwards();
  delay(1500);
  Stop(500);
 
  left();
  delay(900);
  Stop(500);
  
  forwards();
  delay(1500);
  Stop(500);
 
  left();
  delay(900);
  Stop(500);
  
  forwards();
  delay(1500);
  Stop(500);
  
  right();
  delay(1010);
  Stop(500); 
  
  backwards();
  delay(1500);
  Stop(500);
 
  RVright();
  delay(1010);
  Stop(500);
  
  backwards();
  delay(1500);
  Stop(500);
 
  RVright();
  delay(1010);
  Stop(500);
  
  backwards();
  delay(1500);
  Stop(500);
 
  RVright();
  delay(1000);
  Stop(500);
  
  backwards();
  delay(1500);
  Stop(500);
  
  RVleft();
  delay(900);
  Stop(500); 
 
  backwards();
  delay(1500);
  Stop(500);
 
  RVleft();
  delay(900);
  Stop(500);
  
  backwards();
  delay(1500);
  Stop(500);
 
  RVleft();
  delay(930);
  Stop(500);
  
  backwards();
  delay(1500);
  Stop(500);
 
  RVleft();
  delay(950);
  Stop(500);
  
  backwards();
  delay(1500);
  Stop(500);
  
  RVright();
  delay(1010);
  Stop(20000);
  }
 
}
  void forwards() {
  analogWrite(LME, leftspeed);
  analogWrite(RME, rightspeed);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMR, LOW);
  digitalWrite(RMR, LOW);
  //delay(750);
}

void backwards() {
  analogWrite(LME, leftspeed);
  analogWrite(RME, rightspeed);
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);
  digitalWrite(LMR, HIGH);
  digitalWrite(RMR, HIGH);
  //delay(750);
}
  void Stop(int delaytime) {
  digitalWrite(RME, HIGH);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMR, HIGH);
  digitalWrite(RMR, HIGH);
  delay (delaytime);
}
  void right() {
  analogWrite(LME, leftspeed);
  analogWrite(RME, rightspeed);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, LOW);
  digitalWrite(LMR, LOW);
  digitalWrite(RMR, HIGH);
  //delay(425);
}
  void left() {
  analogWrite(LME, leftspeed);
  analogWrite(RME, rightspeed);
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMR, HIGH);
  digitalWrite(RMR, LOW);
 //delay(1000);
}
void RVright() {
  analogWrite(LME, leftspeed);
  analogWrite(RME, rightspeed);
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMR, HIGH);
  digitalWrite(RMR, LOW);
  //delay(425);
}
  void RVleft() {
  analogWrite(LME, leftspeed);
  analogWrite(RME, rightspeed);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, LOW);
  digitalWrite(LMR, LOW);
  digitalWrite(RMR, HIGH);
 //elay(1000);
}

void LeftMotorISR(){
    // adds one to the counter on each motor revolution
    leftcounter++;
}

void RightMotorISR(){
    // adds one to the counter on each motor revolution
    rightcounter++;
}

