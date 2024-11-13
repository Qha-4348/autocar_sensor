import serial
import time

# 아두이노와의 직렬 통신 설정 (포트와 보드레이트를 아두이노 설정에 맞게 변경)
arduino_port = 'COM3'  # 아두이노가 연결된 COM 포트를 확인하세요.
baud_rate = 9600

# 시리얼 포트 연결
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

print(f"아두이노와 연결되었습니다: {arduino_port}")

def read_data():
    line = ser.readline().decode('utf-8').strip()
    return line

try:
    while True:
        # 데이터를 읽고 출력
        data = read_data()
        if data:
            print(data)
        time.sleep(0.1)  # 데이터를 0.1초 간격으로 읽어오기
except KeyboardInterrupt:
    print("프로그램을 종료합니다.")

finally:
    ser.close()
