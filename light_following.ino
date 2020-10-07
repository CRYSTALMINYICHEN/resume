int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int LDR1 = analogRead(A0); // light on the left that controls right tyre
  int LDR2 = analogRead(A1); // light on the right that controls left tyre

  //carForward(100, 100);
  // set speed of tyres based on LDR values (light sensors)
  carForward(LDR2, LDR1);

  // result:
  // it worked!!!
  // our car turned left when the sensor on the right recieves light
  // and it turned right when the sendor on the left recieves light
}

void carStop() {                //  Motor Stop
  digitalWrite(speedPin_M2, 0);
  digitalWrite(directionPin_M1, LOW);
  digitalWrite(speedPin_M1, 0);
  digitalWrite(directionPin_M2, LOW);
}

void carForward(int leftSpeed, int rightSpeed) {    //go forward
  analogWrite (speedPin_M2, leftSpeed);
  digitalWrite(directionPin_M1, HIGH);
  analogWrite (speedPin_M1, rightSpeed);
  digitalWrite(directionPin_M2, LOW);
}
