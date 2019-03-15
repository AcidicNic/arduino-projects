//{led1, led2, led3, ir, state}
const int LA[] = {13, 12, 11, A1}; //(A) First step's leds pins, ir pin, and current state.
const int LB[] = {10, 9, 8, A2}; //(B) Second step
const int LC[] = {7, 6, 5, A3}; //(C) Third step
const int LD[] = {4, 3, 2, A4}; //(C) Fourth step
int b = A5; int udel = 300; //delay, button pin, and setting up the obs var

void setup() {
  //step 1
  pinMode(LA[0], OUTPUT); pinMode(LA[1], OUTPUT); pinMode(LA[2], OUTPUT); pinMode(LA[3], INPUT);
  //step 2
  pinMode(LB[0], OUTPUT); pinMode(LB[1], OUTPUT); pinMode(LB[2], OUTPUT); pinMode(LB[3], INPUT);
  //step 3
  pinMode(LC[0], OUTPUT); pinMode(LC[1], OUTPUT); pinMode(LC[2], OUTPUT); pinMode(LC[3], INPUT);
  pinMode(b, INPUT); //button
}

void loop() {
  sCheck(LA);
  sCheck(LB);
  sCheck(LC);
  sCheck(LD);
}

void sCheck(int *L) {
  if ((digitalRead(L[0]) == HIGH) && (digitalRead(L[1]) == HIGH) && (digitalRead(L[2]) == HIGH) && (digitalRead(L[3]) == LOW)) {
    digitalWrite(L[0], LOW); //all on --> all off
    digitalWrite(L[1], LOW);
    digitalWrite(L[2], LOW);
    delay(udel); //delay inside of statements, because the else at the end should not have a delay.
    return;
  }
  if ((digitalRead(L[0]) == LOW) && (digitalRead(L[1]) == LOW) && (digitalRead(L[2]) == LOW) && (digitalRead(L[3]) == LOW)) {
    digitalWrite(L[0], HIGH); //all off --> one on
    delay(udel);
    return;
  }
  if ((digitalRead(L[0]) == HIGH) && (digitalRead(L[1]) == LOW) && (digitalRead(L[2]) == LOW) && (digitalRead(L[3]) == LOW)) {
    digitalWrite(L[0], HIGH); //one on --> two on
    digitalWrite(L[1], HIGH);
    delay(udel);
    return;
  }
  if ((digitalRead(L[0]) == HIGH) && (digitalRead(L[1]) == HIGH) && (digitalRead(L[2]) == LOW) && (digitalRead(L[3]) == LOW)) {
    digitalWrite(L[0], HIGH); //two on --> all on
    digitalWrite(L[1], HIGH);
    digitalWrite(L[2], HIGH);
    delay(udel);
    return;
  }
  if (digitalRead(b) == LOW) {
    if ((digitalRead(L[0]) == HIGH) && (digitalRead(L[1]) == HIGH) && (digitalRead(L[2]) == HIGH)) {
      digitalWrite(LA[0], LOW); //all on --> all off
      digitalWrite(LA[1], LOW);
      digitalWrite(LA[2], LOW);
      digitalWrite(LB[0], LOW); //b
      digitalWrite(LB[1], LOW);
      digitalWrite(LB[2], LOW);
      digitalWrite(LC[0], LOW); //c
      digitalWrite(LC[1], LOW);
      digitalWrite(LC[2], LOW);
      digitalWrite(LD[0], LOW); //d
      digitalWrite(LD[1], LOW);
      digitalWrite(LD[2], LOW);
      delay(udel);
      return;
    }
    else {
      digitalWrite(LA[0], HIGH); //button pushed && not all on --> all on
      digitalWrite(LA[1], HIGH);
      digitalWrite(LA[2], HIGH);
      digitalWrite(LB[0], HIGH); //b
      digitalWrite(LB[1], HIGH);
      digitalWrite(LB[2], HIGH);
      digitalWrite(LC[0], HIGH); //c
      digitalWrite(LC[1], HIGH);
      digitalWrite(LC[2], HIGH);
      digitalWrite(LD[0], HIGH); //c
      digitalWrite(LD[1], HIGH);
      digitalWrite(LD[2], HIGH);
      delay(udel);
      return;
    }    
  }
  else {
    return; //nothing happened --> nothing happens.
  }
}
