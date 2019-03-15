int trigP = 11;
int echoP = 12;
long dur, inch;

void setup() {
  Serial.begin(9600);

  pinMode(trigP, OUTPUT);
  pinMode(echoP, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop() {
  digitalWrite(trigP, LOW);
  delayMicroseconds(5);
  digitalWrite(trigP, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP, LOW);


  pinMode(echoP, INPUT);
  dur = pulseIn(echoP, HIGH);
  inch = (dur/2)/74;

  Serial.print(inch);
  Serial.print("in\n");

  if (inch < 3) {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  else if (inch > 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
  }
  
  delay(250);
}
