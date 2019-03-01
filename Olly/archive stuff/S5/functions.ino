void s5() {
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

  digitalWrite(leftMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED on by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorBAC, LOW);  // turn the LED on by making the voltage LOW
  delay(1000);                       // wait for 1 second

  digitalWrite(leftMotorENA, LOW);   // turn the LED off (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(rightMotorBAC, LOW);   // turn the LED off by making the voltage LOW
  delay(1200);                        // wait for one and a half seconds
}

void roverStop(){
  digitalWrite(leftMotorENA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorENA, LOW);  // turn the LED on by making the voltage LOW
  digitalWrite(leftMotorBAC, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightMotorBAC, LOW);  // turn the LED on by making the voltage LOW
  delay(1000);
}

