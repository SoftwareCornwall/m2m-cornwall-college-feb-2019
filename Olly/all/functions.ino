void roverStop(){
  digitalWrite(leftMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED on by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorBAC, LOW);  // turn the LED on by making the voltage LOW
  delay(1000);
}

void s3() {
  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorFOR, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorFOR, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorBAC, LOW);
  delay(10000);                      // wait for 1 seconds

  digitalWrite(leftMotorENA, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorFOR, LOW);    // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorFOR, LOW);   // turn the LED off (HIGH is the voltage level)
  delay(1000);                        // wait for 1 seconds

  roverStop();
  
  digitalWrite(leftMotorENA, LOW);   // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  delay(1200);                        // wait for one and a half seconds
}

void s4() {
  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorFOR, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorFOR, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for 1 seconds
  
  digitalWrite(leftMotorENA, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftMotorFOR, LOW);    // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorFOR, LOW);   // turn the LED off (HIGH is the voltage level)
    delay(1000);                        // wait for 1 seconds
  
  digitalWrite(leftMotorENA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, HIGH);  // turn the LED on by making the voltage LOW
  digitalWrite(leftMotorBAC, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorBAC, HIGH);  // turn the LED on by making the voltage LOW
    delay(1000);                        // wait for 1 second
  
  digitalWrite(leftMotorENA, LOW);   // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorBAC, LOW);   // turn the LED off by making the voltage LOW
    delay(1200);                        // wait for one and a half seconds
}

void s5() {

  // Prints out the counter's values to see it working
  Serial.print("Left Counter: ");
  Serial.println(leftCounter);

  Serial.print("Left Motor Speed: ");
  Serial.println(leftSpeed);  

  Serial.print("Right Counter: ");
  Serial.println(rightCounter);

  Serial.print("Right Motor Speed: ");
  Serial.println(rightSpeed);


  if(leftCounter > rightCounter){
      leftSpeed = leftSpeed - 10 ;
      rightSpeed = rightSpeed + 10;
  }

  else if(rightCounter > leftCounter){
      rightSpeed = rightSpeed - 10 ;
      leftSpeed = leftSpeed + 10;
  }

  else { 
    rightSpeed = 175;
    leftSpeed = 175;
  }

  // get current time
  int currentTime = millis();

  if(currentTime - startTime <= 10000){
    forward();
  } 
  
  else {
    stop();
  }
}

void s6() {
  // Prints out the counter's values to see it working
  Serial.print("Left Counter: ");
  Serial.println(leftCounter);

  Serial.print("Left Motor Speed: ");
  Serial.println(leftSpeed);  

  Serial.print("Right Counter: ");
  Serial.println(rightCounter);

  Serial.print("Right Motor Speed: ");
  Serial.println(rightSpeed);


  if(leftCounter > rightCounter){
      leftSpeed = 170;
      rightSpeed = 178;
  }

  else if(rightCounter > leftCounter){
      leftSpeed = 190;
      rightSpeed = 158;
  }

  else { 
    leftSpeed = 180;
    rightSpeed = 168;
  }
  
  // ----- 537 pulses per meter = 898 total
  int pulseTarget = leftCounter;

  if(pulseTarget - startTime <= 898){
    forward();
  } 
  
  else {
    stop();
  }
}

void roverStraight() {
  if(leftCounter > rightCounter){
      leftSpeed = 170;
      rightSpeed = 178;
  }

  else if(rightCounter > leftCounter){
      leftSpeed = 190;
      rightSpeed = 158;
  }

  else { 
    leftSpeed = 180;
    rightSpeed = 168;
  }
}

void forward() {
  analogWrite(leftMotorENA, leftSpeed);   
  analogWrite(rightMotorENA, rightSpeed); 
  digitalWrite(leftMotorFOR, HIGH);   
  digitalWrite(rightMotorFOR, HIGH);  
}

void stop() {
  analogWrite(leftMotorENA, LOW);
  analogWrite(rightMotorENA, LOW);
  digitalWrite(leftMotorFOR, LOW);
  digitalWrite(rightMotorFOR, LOW);
}

// YOU WILL REMEMBER THIS OLLY

void s7New() {
    int a = 0;
    for(a = 0; a < 4; a = a + 1){
      enableMotor();
      forwardForSquare();
      delay(1500);
      turnRightForSquare();
      delay(1070);
      exit(0);
    }
}

// YOU WILL REMEMBER THIS OLLY

void s7() {
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    stop();
    delay(20000);  
}

void s7Demo() {
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    
    enableMotor();
    forwardForSquare();
    delay(1500);
    turnRightForSquare();
    delay(1070);
    stop();
    delay(4000);  
}

void s8() {
  // 3 rights, 4 lefts, 1 right
  
    enableMotor(); // should work now!
    forwardEight();
    rightEight();
    forwardEight();
    rightEight();
    forwardEight();
    rightEight();
    forwardEight(); // almost back to starting position
    leftEight();
    forwardEight();
    leftEight();
    forwardEight();
    leftEight();
    forwardEight();
    leftEight();
    forwardEight();
    rightEight(); // back to start!
    delay(20000);
}

void enableMotor() {
  analogWrite(leftMotorENA, leftSpeed); 
  analogWrite(rightMotorENA, rightSpeed);
}

void forwardEight() {
    digitalWrite(leftMotorFOR, HIGH); 
    digitalWrite(leftMotorBAC, LOW);  
    digitalWrite(rightMotorFOR, HIGH);
    digitalWrite(rightMotorBAC, LOW);
}


void leftEight() {
    digitalWrite(leftMotorFOR, LOW);
    analogWrite(leftMotorBAC, leftSpeed);
    digitalWrite(rightMotorBAC, LOW);
    analogWrite(rightMotorFOR, rightSpeed);
}

void rightEight() {
    analogWrite(leftMotorFOR, leftSpeed);
    digitalWrite(leftMotorBAC, LOW);
    analogWrite(rightMotorBAC, rightSpeed);
    digitalWrite(rightMotorFOR, LOW);
}

  
  void forwardForSquare() {
    digitalWrite(leftMotorFOR, HIGH); 
    digitalWrite(leftMotorBAC, LOW);  
    digitalWrite(rightMotorFOR, HIGH);
    digitalWrite(rightMotorBAC, LOW);
}

  void turnRightForSquare() {
    analogWrite(leftMotorFOR, leftSpeed);
    digitalWrite(leftMotorBAC, LOW);
    analogWrite(rightMotorBAC, rightSpeed);
    digitalWrite(rightMotorFOR, LOW);
  }

void LeftMotorISR() {
  // adds one to counter for every motor revolution

  leftCounter++;
}

void RightMotorISR() {
  // adds one to counter for every motor revolution

  rightCounter++;
}

// Buzzer Work

//  int volume = 0;
//  int a = 0;
void theBuzzer() {
  for(a = 0; a < 10; a = a + 1){
      Serial.print("Buzzer Volume: ");
      Serial.println(volume);
      delay(500);
      analogWrite(buzzer, volume);
      delay(1000);
      analogWrite(buzzer, 0);
      volume = volume + 5;
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    }
}
