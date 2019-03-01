const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; // initiate counter to zero for start 
volatile int rightcounter = 0; // counter could always be reset

void setup()
{
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR,RISING);
     attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
}

void loop() 
    // Just print out the values to show counter operating
{
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

    delay(50);
}

void LeftMotorISR(){
    // adds one to the counter on each motor revolution
    leftcounter++;
}

void RightMotorISR(){
    // adds one to the counter on each motor revolution
    rightcounter++;
}
