//Joystick
int SWp = 8;
int Xp = A0;
int Yp = A1;

//LEDS
int Up = 4;
int Lp = 2;
int Rp = 5;
int Dp = 3;
int Redp = 6;

void setup() {
  
  pinMode(SWp, INPUT);
  digitalWrite(SWp, HIGH);
  Serial.begin(115200);


  pinMode(Xp, INPUT);
  pinMode(Yp, INPUT);
  
  pinMode(Up, OUTPUT);
  pinMode(Lp, OUTPUT);
  pinMode(Rp, OUTPUT);
  pinMode(Dp, OUTPUT);
  pinMode(Redp, OUTPUT);
}

void loop() {

  Serial.print("Switch: ");
  Serial.println(digitalRead(SWp));
  Serial.print("X-axis: ");
  Serial.println(analogRead(Xp));
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Yp));
  Serial.println("\n");

  if(digitalRead(SWp) == 0) {
   digitalWrite(Redp, HIGH);
   Serial.println("red");
  }
  else {
    digitalWrite(Redp, LOW);
  }

  
  if(analogRead(Xp) > 750) {
    digitalWrite(Rp, HIGH);
   Serial.println("right");
  }
  else if(analogRead(Xp) < 750) {
    digitalWrite(Rp, LOW);
  }

  
  if(analogRead(Yp) > 750) {
    digitalWrite(Dp, HIGH);
   Serial.println("down");
  }
  else if(analogRead(Yp) < 750) {
    digitalWrite(Dp, LOW);
  }

 
  if(analogRead(Yp) < 250) {
    digitalWrite(Up, HIGH);
  }
  else if(analogRead(Yp) > 250) {
    digitalWrite(Up, LOW);
  }

  
  if(analogRead(Xp) < 250) {
    digitalWrite(Lp, HIGH);
  }
  else if(analogRead(Xp) > 250) {
    digitalWrite(Lp, LOW);
  }
}
