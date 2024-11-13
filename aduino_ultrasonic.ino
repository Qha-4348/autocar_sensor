const int TRIG_PIN1 = 2;
const int ECHO_PIN1 = 3;
const int TRIG_PIN2 = 4;
const int ECHO_PIN2 = 5;
const int TRIG_PIN3 = 6;
const int ECHO_PIN3 = 7;
const int TRIG_PIN4 = 8;
const int ECHO_PIN4 = 9;
const float speed_Of_Sound = 343.0;    // 음속 (343 m/s)
const float distance_Per_uSec = speed_Of_Sound / 10000.0; // 센티미터 단위에서 1마이크로초 동안 이동한 거리

void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
  pinMode(TRIG_PIN4, OUTPUT);
  pinMode(ECHO_PIN4, INPUT);

  Serial.begin(9600);
}

// 함수: 초음파 센서에서 거리 측정
float measureDistance(int trigPin, int echoPin) {
  // 트리거 핀을 짧은 시간 HIGH로 유지하여 초음파 신호 송신
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 초음파 수신 시간 측정
  float duration = pulseIn(echoPin, HIGH);

  // 왕복 시간을 반으로 나누고 거리로 변환
  duration = duration / 2.0;
  float distanceCm = duration * distance_Per_uSec;

  return distanceCm;
}

void loop() {
  // 각 센서에 대해 거리 측정
  float distanceCm1 = measureDistance(TRIG_PIN1, ECHO_PIN1);
  delay(50);

  float distanceCm2 = measureDistance(TRIG_PIN2, ECHO_PIN2);
  delay(50);

  float distanceCm3 = measureDistance(TRIG_PIN3, ECHO_PIN3);
  delay(50);

  float distanceCm4 = measureDistance(TRIG_PIN4, ECHO_PIN4);
  
  // 측정된 거리 출력
  Serial.print("센서 1: ");
  if (distanceCm1 > 0) {
    Serial.print(distanceCm1);
    Serial.print(" cm");
  }

  Serial.print("  센서 2: ");
  if (distanceCm2 > 0) {
    Serial.print(distanceCm2);
    Serial.print(" cm");
  }

  Serial.print("  센서 3: ");
  if (distanceCm3 > 0) {
    Serial.print(distanceCm3);
    Serial.print(" cm");
  }

  Serial.print("  센서 4: ");
  if (distanceCm4 > 0) {
    Serial.print(distanceCm4);
    Serial.print(" cm");
  }

  Serial.println();

  delay(200);  // 다음 루프 반복을 위한 대기
}
