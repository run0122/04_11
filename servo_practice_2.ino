#include <Servo.h>

const int buttonPin = 7;
const int servoPin = 6;

Servo myservo;

int pos = 0;
int val = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading == HIGH) {
    servo10();
    delay(50);
  }
}

void servo90() {
  for (pos = 0; pos <= 90; pos++) {
    myservo.write(pos);
    delay(15);
  }
}

void servo10() {
  for (pos = val; pos <= val + 10; pos++) {
    myservo.write(pos);
    delay(15);
  }
  val = val + 10;

  if (val == 180) {
    servoTo0();
  }
}

void servoTo0() {
  for (pos = val; pos >= 0; pos--) {
    myservo.write(pos);
    delay(15);
  }
  val = 0;
}