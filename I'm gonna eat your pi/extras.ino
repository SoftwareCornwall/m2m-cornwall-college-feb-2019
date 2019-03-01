
void story_6() {
  rover_forwards();

  Serial.print("Left Counter ");
  Serial.println(leftcounter);
  //Serial.print("Left Speed ");
  //Serial.println(LeftSpeed);
  
  Serial.print("Right Counter ");
  Serial.println(rightcounter);
  //Serial.print("Right Speed ");
  //Serial.println(RightSpeed);

  // int current_time = millis();

  if(leftcounter > rightcounter){
    LeftSpeed = LeftSpeed - 2;
    RightSpeed = RightSpeed + 2;
  }
  else if(rightcounter > leftcounter){
    RightSpeed = RightSpeed - 3;
    LeftSpeed = LeftSpeed + 3;
  }
  else{
    LeftSpeed = 165;
    RightSpeed = 165;
  }
  
  if(rightcounter >= 930){
    rover_hard_stop(2000);
    rover_soft_stop(110000);
  }

}

int centimeters() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  int distance = sonar.ping_cm();
  
  Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  return distance;
}


int down_centimeters() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  int distance = down_sonar.ping_cm();
  return distance;
  Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}

