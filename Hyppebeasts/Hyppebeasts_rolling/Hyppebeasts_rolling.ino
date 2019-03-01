int LME = 9;
int LMR = 7;
int LMF = 8;
int RME = 10;
int RMR = 11;
int RMF = 12;

void setup() {
Serial.begin(115200);
  pinMode(LME, OUTPUT);
  pinMode(RMR, OUTPUT);
  pinMode(RME, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMR, OUTPUT);
  pinMode(LME, OUTPUT);
}

void loop() {
  digitalWrite(LMR, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RME, LOW);
  digitalWrite(RMR, LOW);
  digitalWrite(RMF, LOW);
  digitalWrite(LME, HIGH);
  delay(50);
  digitalWrite(LME, LOW);
  digitalWrite(LMR, HIGH);
  delay(50);
  digitalWrite(LMR, LOW);
  digitalWrite(LMF, HIGH);
  delay(50);
  digitalWrite(LMF, LOW);
  digitalWrite(RME, HIGH);
  delay(50);
  digitalWrite(RME, LOW);
  digitalWrite(RMR, HIGH);
  delay(50);
  digitalWrite(RMR, LOW);
  digitalWrite(RMF, HIGH);
  delay(50);                  
}


