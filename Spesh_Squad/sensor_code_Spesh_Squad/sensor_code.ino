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

int leftspeed = 180;
int rightspeed = 180;
int newSpeed = 180;


void setup() {
  // put your setup code here, to run once:
  pinMode(Forward_L,OUTPUT);
  pinMode(Stat_L,OUTPUT);
  pinMode(Back_L,OUTPUT);
  pinMode(Forward_R,OUTPUT);
  pinMode(Stat_R,OUTPUT);
  pinMode(Back_R,OUTPUT);

    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  
}

void loop() {
/*
  put your main code here, to run repeatedly:
  if(leftcounter > rightcounter){
  left motor speed
  leftspeed = newSpeed;
  rightspeed = new right speed;
  forwards();
*/
    if(leftcounter > rightcounter){
      rightspeed = 184 ;
      analogWrite(Forward_L, rightspeed);
} 
    else if(rightcounter > leftcounter){
      leftspeed = 165;
      analogWrite(Forward_R, leftspeed); 
}
    else if(leftcounter == rightcounter){
      leftspeed = 180;
      rightspeed = 180;
      analogWrite(Forward_L, leftspeed);
      analogWrite(Forward_R, rightspeed);
}
  
// Just print out the values to show counter operating
  Serial.print(" Left Counter ");
  Serial.println(leftcounter);
  Serial.print(" Left Speed ");
  Serial.println(leftspeed);

  Serial.print(" Right Counter ");
  Serial.println(rightcounter);
  Serial.print(" Right Speed ");
  Serial.println(rightspeed);
  
}
 forwards();

  if (millis(10000)

void brake(){

 
}
  

void brake(){
  
  digitalWrite(Stat_L,LOW); // enable motors off
  digitalWrite(Stat_R,LOW);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);
}


void backwards(){
  analogWrite(Stat_L,leftspeed); // enable motors on
  analogWrite(Stat_R,rightspeed);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, HIGH);  // reverse motors on
  digitalWrite(Back_R, HIGH);
}

void forwards(){
  analogWrite(Stat_L, leftspeed); // enable motors on
  analogWrite(Stat_R, rightspeed);

  digitalWrite(Forward_L, HIGH); // forward motors on
  digitalWrite(Forward_R, HIGH);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);
}


void hardstop(){

  digitalWrite(Stat_L,HIGH); // enable motors on
  digitalWrite(Stat_R,HIGH);

  digitalWrite(Forward_L,HIGH); // forward motors on
  digitalWrite(Forward_R,HIGH);

  digitalWrite(Back_L, HIGH);  // reverse motors on
  digitalWrite(Back_R, HIGH);
  
}

void LeftMotorISR(){
  // adds one to the counter on each motor revolution
  leftcounter++;
}


void RightMotorISR(){
  // adds one to the counter on each motor revolution
  rightcounter++;
}

