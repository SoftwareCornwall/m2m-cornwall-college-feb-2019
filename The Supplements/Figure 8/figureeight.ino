
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


//TEMPLATE
//digitalWrite(name, HIGH/LOW);
//delay(1000);

// the setup function runs once when you press reset or power the board


void LeftMotorISR(){

  leftcounter++;
 
}

void RightMotorISR(){

    rightcounter++;
}

void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(LeftM_ENA, OUTPUT);
  pinMode(LeftM_F, OUTPUT);
  pinMode(LeftM_B, OUTPUT);

  pinMode(RightM_ENA, OUTPUT);
  pinMode(RightM_F, OUTPUT);
  pinMode(RightM_B, OUTPUT);

 
  Serial.begin(115200);
  
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);

  Serial.write("RIGHT:");
  Serial.write(rightcounter);
  Serial.write("LEFT: ");
  Serial.write(leftcounter);

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

void backwards() {
  digitalWrite(LeftM_B, HIGH);
  digitalWrite(RightM_B, HIGH);

  digitalWrite(LeftM_F, LOW);
  digitalWrite(RightM_F, LOW);
}

void brake(int time){
  digitalWrite(LeftM_F, HIGH);
  digitalWrite(RightM_F, HIGH);
  digitalWrite(LeftM_B, HIGH);
  digitalWrite(RightM_B, HIGH);
  delay(time);
}

void turnleft(){

 digitalWrite(LeftM_F, LOW);
  
 digitalWrite(RightM_F, HIGH);

 digitalWrite(LeftM_B, HIGH);

 digitalWrite(RightM_B, LOW);

}

void turnright(){
  digitalWrite(LeftM_F, HIGH);
  digitalWrite(RightM_F, LOW);
  digitalWrite(LeftM_B, LOW);
  digitalWrite(RightM_B, HIGH);
}

void turnleftback(){ // similar to the turn left just going backwards 
 digitalWrite(LeftM_F, HIGH);
  
 digitalWrite(RightM_F, LOW);

 digitalWrite(LeftM_B, LOW);

 digitalWrite(RightM_B, HIGH);
}


void turnrightback(){ // same as code above just for turning right
 digitalWrite(LeftM_F, LOW);
  
 digitalWrite(RightM_F, HIGH);

 digitalWrite(LeftM_B, HIGH);

 digitalWrite(RightM_B, LOW);
}

void forwardAndTurnRight(){
   forwards();
   delay(1500); 
   turnright();
   delay(1095);
   brake(1000);
}

void rightsquareforwards(){
  forwards();
   delay(1500); 
   turnright();
   delay(1095);
   brake(1000);

  forwards();
   delay(1500); 
   turnright();
   delay(1095);
   brake(1000);
   
   forwards();
   delay(1500); 
   turnright();
   delay(1095);
   brake(1000);
   
   forwards();
   delay(1500); 
}

void leftsquareforwards(){
   forwards();
   delay(1500); 
   turnleft();
   delay(848); // time for the turn 
   brake(1000);

    forwards();
   delay(1500); 
   turnleft();
   delay(848); // time for the turn 
   brake(1000);

    forwards();
   delay(1500); 
   turnleft();
   delay(851); // time for the turn 
   brake(1000);

    forwards();
   delay(1500); 
   turnleft();
   delay(848); // time for the turn 
   brake(1000);
}

void rightsquarebackwards(){
  
   backwards();
   delay(1500); 
   turnrightback();
   delay(845); // time for the turn 
   brake(1000);
   
   backwards();
   delay(1500); 
   turnrightback();
   delay(845); // time for the turn 
   brake(1000);
   
   backwards();
   delay(1500); 
   turnrightback();
   delay(845); // time for the turn 
   brake(1000);

   backwards();
   delay(1500); 

}

void leftsquarebackwards(){
   backwards();
   delay(1500); 
   turnleftback();
   delay(845); // time for the turn 
   brake(1000);
   
   backwards();
   delay(1500); 
   turnleftback();
   delay(846); // time for the turn 
   brake(1000);
   
   backwards();
   delay(1500); 
   turnleftback();
   delay(848); // time for the turn 
   brake(1000);

   backwards();
   delay(1500); 

}
void forwardAndTurnLeft(){
   forwards();
   delay(1500); 
   turnleft();
   delay(845); // time for the turn 
   brake(1000);
}

void backwardAndTurnLeft(){
   backwards();
   delay(1500); 
   turnleftback();
   delay(845); 
   brake(1000);
  

}

void backwardAndTurnRight(){
   backwards();
   delay(1500); 
   turnrightback();
   delay(950);
   brake(1000);
}

void figureOf8forward() { // forwards version of the figure 8 
 forwardAndTurnRight();
 forwardAndTurnRight();
 forwardAndTurnRight();
 
 forwardAndTurnLeft();
 forwardAndTurnLeft();
 forwardAndTurnLeft();
 forwardAndTurnLeft();
 
 forwardAndTurnRight(); 
}


void figureOf8backward() { // Backwards version of figure 8. 
 backwardAndTurnRight();
 backwardAndTurnRight();
 backwardAndTurnRight();

 backwardAndTurnLeft();
 backwardAndTurnLeft();
 backwardAndTurnLeft();
 backwardAndTurnLeft();
 
 backwardAndTurnRight();

}

void loop(){
 enablemot();
 //figureOf8forward();
 //figureOf8backward();

rightsquareforwards();
leftsquareforwards();
rightsquarebackwards();
leftsquarebackwards();
 
 exit(0);

}






