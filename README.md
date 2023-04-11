# 04_11

## 1. math

조도센서를 통해 값을 입력받고 Max값과 Min값을 찾는 실습을 했습니다. 조도센서를 통해서 배열에 값을 입력하고 이 배열 내에서의 Max 값과 Min값을 출력하는 프로그램을 작성하였습니다. 

비슷한 코드로는 Examples -> Analog -> Calibration를 참조할 수 있습니다.

## 2. Servo

버튼을 누를 때마다 Servo 모터의 각도가 변경되도록 하는 함수를 구현했습니다. 코드 이름은 servo_practice_2입니다.  

초기에는 채터링을 방지하기 위해서 

```
void loop() {
  int reading = digitalRead(buttonPin);
  if (reading == HIGH) {
    servo10();
    delay(50);
  }
}
```
이렇게 구현했지만, 

```
int buttonState = LOW;         // 버튼 상태 변수
int lastButtonState = LOW;     // 마지막 버튼 상태 변수
unsigned long lastDebounceTime = 0;  // 마지막 버튼 입력 시간
unsigned long debounceDelay = 50;    // 디바운스 시간

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
```
이를 millis()를 이용한 디바운싱 코드로 변경하였습니다. 코드 이름은 servo_practice_3입니다.
