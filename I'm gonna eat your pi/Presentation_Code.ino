int LeftForwards = 8;
int LeftBackwards = 7;
int LeftMotor = 9;
int RightMotor = 10;
int RightForwards = 12;
int RightBackwards = 11;
int LeftSpeed = 165;
int RightSpeed = 165;

int distance = 0;

int finish_story = 1;

#include <NewPing.h>

#define DOWN_TRIGGER_PIN 13
#define DOWN_ECHO_PIN 17
#define TRIGGER_PIN 4 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing down_sonar(DOWN_TRIGGER_PIN, DOWN_ECHO_PIN, MAX_DISTANCE);

const int LEFT_FEEDBACK = 2; //pin numbers on rover
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; //Initiate counter to zero for start
volatile int rightcounter = 0; //counter could always be reset

int start_time = millis();


// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);
  int distance = sonar.ping_cm();
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
  
  pinMode(LeftForwards, OUTPUT);
  pinMode(LeftBackwards, OUTPUT);
  pinMode(LeftMotor, OUTPUT);
  pinMode(RightMotor, OUTPUT);
  pinMode(RightForwards, OUTPUT);
  pinMode(RightBackwards, OUTPUT);
}

void rover_forwards_with_delay(int delayTime) {
  digitalWrite(LeftMotor, HIGH);   
  digitalWrite(LeftForwards, HIGH);   
  digitalWrite(LeftBackwards, LOW);  
  digitalWrite(RightMotor, HIGH);   
  digitalWrite(RightForwards, HIGH);   
  digitalWrite(RightBackwards, LOW);   
  delay(delayTime);
}

void rover_right() {
  analogWrite(LeftMotor, LeftSpeed);   
  digitalWrite(LeftForwards, HIGH);   
  digitalWrite(LeftBackwards, LOW);  
  analogWrite(RightMotor, RightSpeed);   
  digitalWrite(RightForwards, LOW);   
  digitalWrite(RightBackwards, HIGH);   
}

void rover_left() {
  analogWrite(LeftMotor, LeftSpeed);   
  digitalWrite(LeftForwards, LOW);   
  digitalWrite(LeftBackwards, HIGH);  
  analogWrite(RightMotor, RightSpeed);   
  digitalWrite(RightForwards, HIGH);   
  digitalWrite(RightBackwards, LOW); 
}

void rover_forwards() {
  analogWrite(LeftMotor, LeftSpeed);   
  digitalWrite(LeftForwards, HIGH);   
  digitalWrite(LeftBackwards, LOW);  
  analogWrite(RightMotor, RightSpeed);   
  digitalWrite(RightForwards, HIGH);   
  digitalWrite(RightBackwards, LOW);   

}

void rover_backwards() {
  digitalWrite(LeftMotor, HIGH);   
  digitalWrite(LeftForwards,LOW);   
  digitalWrite(LeftBackwards, HIGH);  
  digitalWrite(RightMotor, HIGH);   
  digitalWrite(RightForwards,LOW);   
  digitalWrite(RightBackwards, HIGH);   
}

void rover_soft_stop(int delayTime) {
  digitalWrite(LeftMotor, LOW);   
  digitalWrite(LeftForwards,LOW);   
  digitalWrite(LeftBackwards, LOW);   
  digitalWrite(RightMotor, LOW);   
  digitalWrite(RightForwards,LOW);  
  digitalWrite(RightBackwards, LOW);   
  delay(delayTime);
}

void rover_hard_stop(int delayTime) {
  digitalWrite(LeftMotor, HIGH);   
  digitalWrite(LeftForwards,HIGH);   
  digitalWrite(LeftBackwards, HIGH);   
  digitalWrite(RightMotor, HIGH);   
  digitalWrite(RightForwards,HIGH);  
  digitalWrite(RightBackwards, HIGH);  
  delay(delayTime); 
}

void backwards_figure_eight() {

  rover_backwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1140);
  rover_hard_stop(1000);
  

  rover_backwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1140);
  rover_hard_stop(1000);
  

  rover_backwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1140);
  rover_hard_stop(1000);

  rover_backwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1040);
  rover_hard_stop(1000);
  
  rover_backwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_left();
  delay(1055);
  rover_hard_stop(1000);
  
  rover_backwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_left();
  delay(1055);
  rover_hard_stop(1000);
  
  rover_backwards();
  delay(1545);
  rover_hard_stop(1000);

  rover_left();
  delay(1045);
  rover_hard_stop(1000);

  rover_backwards();
  delay(1500);
  rover_hard_stop(1000);

}

void forwards_figure_eight() {
      
  rover_forwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1140);
  rover_hard_stop(1000);

  rover_forwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1140);
  rover_hard_stop(1000);

  rover_forwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_right();
  delay(1140);
  rover_hard_stop(1000);

  rover_forwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_left();
  delay(1040);
  rover_hard_stop(1000);
  
  rover_forwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_left();
  delay(1050);
  rover_hard_stop(1000);
  
  rover_forwards();
  delay(1550);
  rover_hard_stop(1000);

  rover_left();
  delay(1050);
  rover_hard_stop(1000);
  
  rover_forwards();
  delay(1555);
  rover_hard_stop(1000);

  rover_left();
  delay(1045);
  rover_hard_stop(1000);

  rover_forwards();
  delay(1510);
  rover_hard_stop(1000);

  rover_right();
  delay(1150);
  rover_hard_stop(1000);


}

void rover_sensor_forwards(){

  while(finish_story == 2){
    int distance = centimeters();
  
    rover_forwards();
  
    if (distance > 10 and distance < 15) {
    
      rover_hard_stop(1000);
      
      rover_left();
      
      delay(1030);

      finish_story = 3;
      
    }
    
  }

  

}

void rover_sensor_down(){

  while(finish_story == 3){
  
    int distance = down_centimeters();

    delay(50);

    rover_forwards();

    if (distance >13) {

      rover_hard_stop(500);

      rover_backwards();

      delay(250);

      rover_left();
            
      delay(2025);

      rover_forwards();

      delay(5500);

      rover_left();

      delay(4120);

      rover_right();

      delay(4120);

      rover_hard_stop(500);

      exit(0);
      
    } 
  }

}


// the loop function runs over and over again forever
void loop() {


  if (finish_story == 1){

    forwards_figure_eight();
  
    finish_story = 2;
  
  }

  if (finish_story == 2) {
  
    rover_sensor_forwards();
  
    finish_story = 3;

  }

  if (finish_story == 3){
  
    rover_sensor_down();

  }

}

void LeftMotorISR(){
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}

