int led1 = 2;
int led2 = 3;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  Serial.write("Hello World!\nYeet");
  
  // initialize digital pins as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10000);                       // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
  
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
}
