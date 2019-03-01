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
  */
  forwards();

  if(leftspeed > rightspeed){
    analogWrite(Stat_L, rightspeed);
  } 
    else if(rightspeed > leftspeed){
      analogWrite(Stat_R, leftspeed); 
    }
    else if(leftspeed = rightspeed){
      analogWrite(Stat_L, leftspeed);
      analogWrite(Stat_R, rightspeed);
  }
  
      Serial.println(rightcounter);
      Serial.println(leftcounter);
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

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);
}

void forwards(){
  analogWrite(Stat_L,leftspeed); // enable motors on
  analogWrite(Stat_R,rightspeed);

  digitalWrite(Forward_L,HIGH); // forward motors on
  digitalWrite(Forward_R,HIGH);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);
}

void rightturn(){
  digitalWrite(Stat_L,HIGH); // enable motors on
  digitalWrite(Stat_R,HIGH);

  digitalWrite(Forward_L,HIGH); // forward motors on
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
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

