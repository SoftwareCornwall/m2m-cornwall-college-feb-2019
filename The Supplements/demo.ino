// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>


int LeftM_ENA = 9; //ENABLE LEFT
int LeftM_F = 8; //ROVER FORWARDS
int LeftM_B = 7; //ROVER BACKWARDS


int RightM_ENA = 10; //ENABLE RIGHT
int RightM_F = 12; //ROVER FORWARDS
int RightM_B = 11; //ROVER BACKWARDS



const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; 
volatile int rightcounter = 0;

int left_speed = 200;
int right_speed = 190;


#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  int distance = sonar.ping_cm();

  pinMode(LeftM_ENA, OUTPUT);
  pinMode(LeftM_F, OUTPUT);
  pinMode(LeftM_B, OUTPUT);

  pinMode(RightM_ENA, OUTPUT);
  pinMode(RightM_F, OUTPUT);
  pinMode(RightM_B, OUTPUT);

 
  Serial.begin(115200);
  
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  int distance = sonar.ping_cm();
 enablemot();
 forwards();
 
 if (distance >= 8 and distance <=10){
  brake(1000);
  turnright();
  delay(1300);
  forwards();
 }
  



 forwardAndTurnRight();
 forwardAndTurnRight();
 forwardAndTurnRight();

 forwardAndTurnLeft();
 forwardAndTurnLeft();
 forwardAndTurnLeft();
 forwardAndTurnLeft();
 
 forwardAndTurnRight();

 exit(0);
 
  
}


void LeftMotorISR(){

  leftcounter++;
 
}

void RightMotorISR(){

    rightcounter++;
}


void forwards() { 
  digitalWrite(LeftM_B, LOW);
  digitalWrite(RightM_B, LOW);
  
  
  digitalWrite(LeftM_F, HIGH);
  digitalWrite(RightM_F, HIGH);
}


void disablemot() {
  digitalWrite(LeftM_ENA, LOW);
  digitalWrite(RightM_ENA, LOW);
}

void enablemot() {
  analogWrite(LeftM_ENA, left_speed);
  analogWrite(RightM_ENA, right_speed);
}


void turnleft(){

 digitalWrite(LeftM_F, LOW);
  
 digitalWrite(RightM_F, HIGH);

 digitalWrite(LeftM_B, HIGH);

 digitalWrite(RightM_B, LOW);

}

void brake(int time){
  digitalWrite(LeftM_F, HIGH);
  digitalWrite(RightM_F, HIGH);
  digitalWrite(LeftM_B, HIGH);
  digitalWrite(RightM_B, HIGH);
}
void turnright(){
  digitalWrite(LeftM_F, HIGH);
  digitalWrite(RightM_F, LOW);
  digitalWrite(LeftM_B, LOW);
  digitalWrite(RightM_B, HIGH);
}

void forwardAndTurnRight(){
   forwards();
   delay(1500); 
   turnright();
   delay(950);
   brake(1000);
}

void forwardAndTurnLeft(){
   forwards();
   delay(1500); 
   turnleft();
   delay(900); // <- Change this
   brake(1000);
}

