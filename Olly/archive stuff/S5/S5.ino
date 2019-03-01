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
  s3();
}

