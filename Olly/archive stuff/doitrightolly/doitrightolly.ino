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
  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorFOR, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorFOR, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(10000);                       // wait for ten seconds
  
  digitalWrite(leftMotorENA, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorFOR, LOW);    // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorFOR, LOW);   // turn the LED off (HIGH is the voltage level)
    delay(1500);                        // wait for one and a half seconds
  
  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, HIGH);  // turn the LED on by making the voltage LOW
  digitalWrite(leftMotorBAC, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorBAC, HIGH);  // turn the LED on by making the voltage LOW
    delay(1000);                        // wait for one second
  
  digitalWrite(leftMotorENA, LOW);   // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorBAC, LOW);   // turn the LED off by making the voltage LOW
    delay(1500);                        // wait for one and a half seconds
}
