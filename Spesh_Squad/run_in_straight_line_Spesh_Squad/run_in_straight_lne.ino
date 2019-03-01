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

   int forward_delay = 2400;
   int rightturn_delay = 1053;
   int leftturn_delay = 1050;

   forwards();
   delay(forward_delay);
   rightturn();
   delay (rightturn_delay);
   forwards();
   delay(forward_delay);
   rightturn();
   delay (rightturn_delay);
   forwards();
   delay(forward_delay);
   rightturn();
   delay (rightturn_delay);
   forwards();
   delay(forward_delay);
   forwards ();
   delay (forward_delay);
   leftturn ();
   delay (leftturn_delay);
   forwards ();
   delay (forward_delay);
   leftturn();
   delay (1020);
   forwards ();
   delay (2750);
   leftturn ();
   delay (920);
   forwards ();
   delay (1650);
   brake(50000);
   
 
 
}
  

void brake(int time){
  
  digitalWrite(Stat_L,LOW); // enable motors off
  digitalWrite(Stat_R,LOW);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);

  delay (time);
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
  Serial.println("forwards");
}

void rightturn(){
  analogWrite(Stat_L, leftspeed); // enable motors on
  analogWrite(Stat_R, rightspeed);

  digitalWrite(Forward_L, HIGH); // forward motors on
  digitalWrite(Forward_R, LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, HIGH);
  Serial.println("rightturn");
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
void hardstop(int time){

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

