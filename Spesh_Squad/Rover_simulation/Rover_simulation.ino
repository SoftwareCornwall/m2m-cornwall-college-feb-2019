int Forward_L = 8;
int Forward_R = 12;
int Stat_L = 9;
int Stat_R = 10;
int Back_L = 7;
int Back_R = 11;

// the setup function tells us which LED to use.
void setup() {
  // initialize digital pin D3 as an output.
  pinMode(Forward_L,OUTPUT);
  pinMode(Stat_L,OUTPUT);
  pinMode(Back_L,OUTPUT);
  pinMode(Forward_R,OUTPUT);
  pinMode(Stat_R,OUTPUT);
  pinMode(Back_R,OUTPUT);
}

// The loop function tells us how quickly the LED to turn on and off 
// including time when off and when on.
void loop() {
  /* Yello LED = forwards
   * Green LED = enable
   * Red LED = backwards
   * Forwards for 10 seconds.*/
  digitalWrite(Stat_L,HIGH); // enable motors on
  digitalWrite(Stat_R,HIGH);

  digitalWrite(Forward_L,HIGH); // forward motors on
  digitalWrite(Forward_R,HIGH);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);

  delay(1000);

  //Stop for 5 seconds.
  digitalWrite(Stat_L,LOW); // enable motors off
  digitalWrite(Stat_R,LOW);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);

  delay(1000);


  //Reverse for 1 second
  digitalWrite(Stat_L, HIGH);
  digitalWrite(Stat_R, HIGH);
  
  digitalWrite(Back_L, HIGH);
  digitalWrite(Back_R, HIGH);
  
  digitalWrite(Forward_L, LOW);
  digitalWrite(Forward_R, LOW);
  
  delay(1000);

  //Stops the rover when 1 second reverse is done and makes sure that the
  //rover has stopped.
  digitalWrite(Stat_L,LOW); // enable motors off
  digitalWrite(Stat_R,LOW);

  digitalWrite(Forward_L,LOW); // forward motors off
  digitalWrite(Forward_R,LOW);

  digitalWrite(Back_L, LOW);  // reverse motors off
  digitalWrite(Back_R, LOW);

  delay(5000);

}
