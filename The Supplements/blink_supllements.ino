
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

int left_speed = 215;
int right_speed = 200;


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

void backwards(int time) {

  digitalWrite(LeftM_B, HIGH);
  
  digitalWrite(RightM_B, HIGH);

  delay(time);

  digitalWrite(LeftM_B, LOW);
  
  digitalWrite(RightM_B, LOW);

}

void brake(int time) {

  digitalWrite(LeftM_F, HIGH);
  
  digitalWrite(RightM_F, HIGH);

  digitalWrite(LeftM_B, HIGH);

  digitalWrite(RightM_B, HIGH);

  delay(time);

}

void loop() {

  enablemot();
  forwards();

  int totalreps = leftcounter + rightcounter
  
  if  (totalreps >= 2125) {
    brake(6000);
    disablemot();
   
    }




  Serial.print("Left Counter "); // Feedback for buttons
  Serial.println(leftcounter);

  Serial.print("Right Counter ");
  Serial.println(rightcounter);
}





