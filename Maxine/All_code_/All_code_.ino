int LME = 9;
int LMR = 7;
int LMF = 8;
int RME = 10;
int RMR = 11;
int RMF = 12;
int leftSpeed = 167;
int rightSpeed = 155;
int rightSpeed2 = 255;
int leftSpeed2 = 65;
const int LEFT_FEEDBACK = 2;//pin numbers on rover
const int RIGHT_FEEDBACK = 3;

volatile int leftcounter =0; // initiate counter to zero for start 
volatile int rightcounter =0; // counter could always be reset 


#include <NewPing.h>

#define TRIGGER_PIN  4 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5
// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// the setup function runs once when you press reset or power the board
void setup() {
int distance = sonar.ping_cm();
  
 
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
    
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);

  // initialize digital pin LED_BUILTIN as an output.
  
    pinMode(LME, OUTPUT);
    pinMode(LMR, OUTPUT);
    pinMode(LMF, OUTPUT);
    pinMode(RME, OUTPUT);
    pinMode(RMR, OUTPUT);
    pinMode(RMF, OUTPUT);
}


// the loop function runs over and over again forever
void loop() 
{

  donthit();

  
}


void notfalling(){
   motorsForward();
delay(50);
  int distance = sonar.ping_cm();

 if(distance >13){
  reverse();
  delay(300);
  everythingoff(10000);
  Serial.print(sonar.ping_cm());
  delay(1100);
 }
}

void donthit(){
  motorsForward();
  delay(50);
  int distance = sonar.ping_cm();

  if(distance >8 and distance <10){
    
    leftturn();

    delay(1100);
    motorsForward();
 }

}

  void fig8(){
  rightsquare();
  stopMotors();
  delay(500);
  leftsquare();
  stopMotors();
  delay(50000);


  
}

void rightsquare(){
  motorsForward();
  delay(1950);
  rightturn();
  delay(1350);

  motorsForward();
  delay(1950); 
  rightturn();
  delay(1400);

  motorsForward();
  delay(2000);
  rightturn();
  delay(1400);
  
  motorsForward();
  delay(2000);
  leftturn();
  delay(1200);
}


void leftsquare(){
    
  motorsForward();
  delay(2000);
  leftturn();
  delay(1100);

      
  motorsForward();
  delay(2000);
  leftturn();
  delay(1100);

  motorsForward();
  delay(2000);
  leftturn();
  delay(1200);

   motorsForward();
  delay(2000);
  rightturn();
  delay(1300);

   

}

void leftturn(){
  digitalWrite(RMF, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(LMF, LOW);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LMR, HIGH);   // turn the LED on (HIGH is the voltage level)  
}



void rightturn(){ 
  digitalWrite(LMF, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(RMF, LOW);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(RMR, HIGH);   // turn the LED on (HIGH is the voltage level)  
}







void story56(){

  motorsForward();


  //just print out the values to show counter operating 
  Serial.print("Left Counter ");
  Serial.println(leftcounter);
  
  Serial.print("Right Counter ");
  Serial.println(rightcounter);
  delay(20);


  
  if(leftcounter > rightcounter){
    leftSpeed = leftSpeed - 3 ;
    rightSpeed = rightSpeed + 3 ;}
  
  else if(rightcounter > leftcounter){
    rightSpeed = rightSpeed - 3 ;
    leftSpeed = leftSpeed + 3 ;}
  
  else {
    rightSpeed = 167;
    leftSpeed = 167;
  }
  
    if(millis() >= 10000) { 
      everythingoff(50000);
    }
}


void LeftMotorISR(){
  //adds ontr to the counter on each motor revilution
  leftcounter++;
}

void RightMotorISR(){
  //adds ontr to the counter on each motor revolution
  rightcounter++;
}


void story4(){ 
  motorsForward();
  delay(1000);   

  stopMotors();
  delay(1000);

  reverse();
  delay(1000);

  everythingoff(30000);

}

void story3(){
  motorsForward();
  delay (10000);
  stopMotors();
  delay(1000);
  reverse();
  delay (1000);
  stopMotors();
  delay (1000);
  everythingoff(30000);
}


void motorsForward(){
  //function makes rova go forward
  analogWrite(LME, leftSpeed);   // turn the LED on (HIGH is the voltage level)

  analogWrite(RME, rightSpeed);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(RMR, LOW);   // turn the LED on (HIGH is the voltage level)  

  digitalWrite(LMR, LOW);   // turn the LED on (HIGH is the voltage level)  
  
  digitalWrite(LMF, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(RMF, HIGH);   // turn the LED on (HIGH is the voltage level)
 
  
}




void stopMotors(){
  // THIS NEXT PART IS THE STOP

 digitalWrite(LME, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(RME, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(LMF, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(RMF, HIGH);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(LMR, HIGH);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(RMR, HIGH);   // turn the LED on (HIGH is the voltage level)


}

void reverse() {
    digitalWrite(LMF, LOW);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(RMF, LOW);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LME, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(RME, HIGH);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(LMR, HIGH);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(RMR, HIGH);   // turn the LED on (HIGH is the voltage level)
}


void everythingoff(int time){
   digitalWrite(LME, LOW);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(RME, LOW);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(LMF, LOW);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(RMF, LOW);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(LMR, LOW);   // turn the LED on (HIGH is the voltage level)
   
  digitalWrite(RMR, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(time);
}




 /*analogWrite(LME, leftSpeed);   // turn the LED on (HIGH is the voltage level)

  analogWrite(RME, rightSpeed);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LMF, leftSpeed);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(RMF, rightSpeed);   // turn the LED on (HIGH is the voltage level)

  delay(15000);

  everythingoff(3000);

  analogWrite(RME, rightSpeed2);   // turn the LED on (HIGH is the voltage level)
  
  analogWrite(LME, leftSpeed2);   // turn the LED on (HIGH is the voltage level)  

  digitalWrite(LMF, leftSpeed2);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(RMF, rightSpeed2);   // turn the LED on (HIGH is the voltage level)

  delay(15000); */

