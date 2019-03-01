const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; 
volatile int rightcounter = 0;







void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Left Counter ");
  Serial.print(leftcounter);

  Serial.println("Right Counter ");
  Serial.print(rightcounter);

}



void LeftMotorISR(){

  leftcounter++;
 
}

void RightMotorISR(){

    rightcounter++;
}

