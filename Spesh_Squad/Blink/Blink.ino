int led1 = 2;
int led2 = 3;

// the setup function tells us which LED to use.
void setup() {
  // initialize digital pin D3 as an output.
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

// The loop function tells us how quickly the LED to turn on and off 
// including time when off and when on.
void loop() {
  digitalWrite(led1,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led1,LOW);    // turn the LED off by making the voltage LOW
  delay(0);                       // wait for a second
  digitalWrite(led2,HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(led2,LOW);    // turn the LED off by making the voltage LOW
  delay(0);
}
