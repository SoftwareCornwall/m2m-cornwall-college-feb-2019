int LME = 9;
int LMR = 7;
int LMF = 8;
int RME = 10;
int RMR = 11;
int RMF = 12;
int leftspeed = 195;
int rightspeed = 190;

const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; // initiate counter to zero for start 
volatile int rightcounter = 0; // counter could always be reset

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

}

void loop() {

   
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
  Stop(1000);
 
  right();
  delay(1010);
  Stop(1000);
  
  forwards();
  delay(1500);
  Stop(1000);
 
  right();
  delay(1010);
  Stop(1000);
  
  forwards();
  delay(1500);
  Stop(1000);
 
  right();
  delay(1010);
  Stop(1000);
  
  forwards();
  delay(1500);
  Stop(1000);
  
  left();
  delay(900);
  Stop(1000); 
 
  forwards();
  delay(1500);
  Stop(1000);
 
  left();
  delay(900);
  Stop(1000);
  
  forwards();
  delay(1500);
  Stop(1000);
 
  left();
  delay(900);
  Stop(1000);
  
  forwards();
  delay(1500);
  Stop(1000);
 
  left();
  delay(900);
  Stop(1000);
  
  forwards();
  delay(1500);
  Stop(1000);
  
  right();
  delay(1010 );
  Stop(10000); 
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

