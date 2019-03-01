// defines motor functions below
int leftMotorENA = 9; // rover enabled
int leftMotorFOR = 8; // rover forwards
int leftMotorBAC = 7; // rover backwards

int rightMotorENA = 10; // rover enabled
int rightMotorBAC = 11; // rover forwards
int rightMotorFOR = 12; // rover backwards

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as an output.
  pinMode(leftMotorENA, OUTPUT);
  pinMode(leftMotorBAC, OUTPUT);
  pinMode(leftMotorFOR, OUTPUT);
  pinMode(rightMotorENA, OUTPUT);
  pinMode(rightMotorBAC, OUTPUT);
  pinMode(rightMotorFOR, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
// fun (almost working) light show. Version 1 of many to come 
  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(leftMotorBAC, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(leftMotorFOR, HIGH);    // turn the LED off by making the voltage LOW
    delay(50);
  digitalWrite(rightMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(rightMotorBAC, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(rightMotorFOR, HIGH);    // turn the LED off by making the voltage LOW

  digitalWrite(leftMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(leftMotorBAC, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(leftMotorFOR, LOW);    // turn the LED off by making the voltage LOW
    delay(50);    
  digitalWrite(rightMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(rightMotorBAC, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(rightMotorFOR, LOW);    // turn the LED off by making the voltage LOW
    delay(500);
    
  digitalWrite(leftMotorENA, LOW);   
    delay(50);
  digitalWrite(rightMotorENA, LOW);    
    delay(50);
  digitalWrite(leftMotorBAC, LOW);    
    delay(50);
  digitalWrite(rightMotorBAC, LOW);    
    delay(50);

  digitalWrite(leftMotorENA, HIGH);   
    delay(50);
  digitalWrite(rightMotorENA, HIGH);    
    delay(50);
  digitalWrite(leftMotorFOR, HIGH);    
    delay(50);
  digitalWrite(rightMotorFOR, HIGH);    
    delay(50);

  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(rightMotorENA, HIGH);    // turn the LED off by making the voltage LOW
    delay(50);
  digitalWrite(leftMotorBAC, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
  digitalWrite(rightMotorBAC, HIGH);    // turn the LED off by making the voltage LOW
    delay(50);

  digitalWrite(leftMotorENA, LOW);   
    delay(50);
  digitalWrite(rightMotorENA, LOW);    
    delay(50);
  digitalWrite(leftMotorFOR, LOW);    
    delay(50);
  digitalWrite(rightMotorFOR, LOW);    
    delay(50);
}
