const int NUM_READINGS = 10; // 데이터 배열의 크기
int readings[NUM_READINGS]; // 데이터 배열
int readIndex = 0; // 배열 인덱스
int total = 0; // 배열 값의 합계

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 조도센서에서 값을 읽어옴
  int value = analogRead(A1);
  delay(100);

  // 배열에 값을 추가
  total -= readings[readIndex];
  readings[readIndex] = value;
  total += readings[readIndex];
  readIndex = (readIndex + 1) % NUM_READINGS;

  // 최대값과 최소값 계산
  int maxVal = readings[0];
  int minVal = readings[0];
  for (int i = 1; i < NUM_READINGS; i++) {
    if (readings[i] > maxVal) {
      maxVal = readings[i];
    }
    if (readings[i] < minVal) {
      minVal = readings[i];
    }
  }

  // 최대값과 최소값 출력
  Serial.print("Max value: ");
  Serial.println(maxVal);
  Serial.print("Min value: ");
  Serial.println(minVal);
}