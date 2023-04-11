#include <Servo.h>

const int buttonPin = 7;
const int servoPin = 6;

Servo myservo;

int pos = 0;
int val = 0;

int buttonState = LOW;         // 버튼 상태 변수
int lastButtonState = LOW;     // 마지막 버튼 상태 변수
unsigned long lastDebounceTime = 0;  // 마지막 버튼 입력 시간
unsigned long debounceDelay = 50;    // 디바운스 시간

void setup() {
  pinMode(buttonPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // 버튼 입력 상태가 변경된 경우
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // 버튼 입력 시간 저장
  }

  // 일정 시간이 지난 후에 버튼 입력 상태를 확인하여 디바운싱 처리
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 버튼 입력이 안정화된 경우
    if (reading != buttonState) {
      buttonState = reading;

      // 버튼이 눌렸을 때
      if (buttonState == HIGH) {
        servo10();
      }
    }
  }

  lastButtonState = reading;
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