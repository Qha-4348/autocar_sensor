#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

static const int RXPin = 8; // GPS의 TX 핀에 연결된 아두이노 RX 핀
static const int TXPin = 7; // GPS의 RX 핀에 연결된 아두이노 TX 핀
static const uint32_t GPSBaud = 38400; // GPS 모듈의 통신 속도

SoftwareSerial ss(RXPin, TXPin); // 소프트웨어 시리얼 객체 생성
TinyGPSPlus gps; // TinyGPSPlus 객체 생성

void setup()
{
  Serial.begin(9600);  // 시리얼 모니터 통신 시작
  ss.begin(GPSBaud);   // GPS 모듈과의 통신 시작
  Serial.println(F("GPS 위치 수신 시작..."));
}

void loop()
{
  // GPS로부터 데이터 수신
  while (ss.available() > 0) 
  {
    char c = ss.read(); // 한 문자 읽기
    gps.encode(c); // NMEA 데이터를 디코드하여 gps 객체에 저장

    // NMEA 데이터가 수신된 경우 출력
    Serial.print(c); // 읽은 문자를 시리얼 모니터에 출력
  }

  delay(1000); // 1초마다 수신 상태 출력 (1Hz)
}
