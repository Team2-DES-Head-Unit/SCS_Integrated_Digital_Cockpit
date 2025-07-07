import socket
import struct
import time
import threading # 스레딩 모듈 임포트
import RPi.GPIO as GPIO

from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad

ENCODER_PIN = 17
TRIG_PIN = 24
ECHO_PIN = 23

CIRCUMFERENCE = 0.214  # 바퀴 둘레 (미터)
PERIOD = 0.1           # 센서 데이터 업데이트 및 메인 루프 주기 (초)

counter = 0
start_time = time.time()

GPIO.setmode(GPIO.BCM)
GPIO.setup(ENCODER_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)

def count(channel):
    global counter
    counter += 1

speed = 0.0
distance = 0.0

GPIO.add_event_detect(ENCODER_PIN, GPIO.RISING, callback=count)

def get_distance():
    GPIO.output(TRIG_PIN, GPIO.HIGH)
    time.sleep(0.000015)  # 15 마이크로초
    GPIO.output(TRIG_PIN, GPIO.LOW)
    
    pulse_start_time = time.time()
    timeout = pulse_start_time + 0.1 # 100ms 타임아웃
    while GPIO.input(ECHO_PIN) == GPIO.LOW and time.time() < timeout:
        pulse_start_time = time.time()
    
    if time.time() >= timeout: # 타임아웃 발생 시
        return -1.0 # 에러 또는 범위 밖을 나타내는 값 반환

    pulse_end_time = time.time()
    timeout = pulse_end_time + 0.1 # 100ms 타임아웃
    while GPIO.input(ECHO_PIN) == GPIO.HIGH and time.time() < timeout:
        pulse_end_time = time.time()
    
    if time.time() >= timeout: # 타임아웃 발생 시
        return -1.0 # 에러 또는 센서 고착

    duration = pulse_end_time - pulse_start_time
    distance = (340.0 * duration) / 2 * 100 # cm 단위
    return round(distance, 2)


# ControlData 구조체와 동일한 메모리 레이아웃
def create_control_data(throttle, steering, distance, speed, gear_state, indicator_state):
    return struct.pack(
        'ffffBBBBBB',
        throttle, steering, distance, speed,
        gear_state['P'], gear_state['D'], gear_state['R'], gear_state['N'],
        indicator_state['l'], indicator_state['r']
    )





class GamepadReader(threading.Thread):
    def __init__(self, gamepad):
        super().__init__()
        self.gamepad = gamepad
        self._latest_data = None
        self._lock = threading.Lock() 
        self._running = True

    def run(self):
        class DefaultGamepadInput:
            class AnalogStick:
                x = 0.0
                y = 0.0
            analog_stick_right = AnalogStick()
            analog_stick_left = AnalogStick()
            button_x = 0
            button_y = 0
            button_a = 0
            button_b = 0
            button_l1 = 0
            button_r1 = 0
        
        with self._lock:
            self._latest_data = DefaultGamepadInput()

        while self._running:
            try:
                data = self.gamepad.read_data()
                with self._lock:
                    self._latest_data = data
            except Exception as e:
                time.sleep(0.1)

    def get_latest_data(self):
        with self._lock:
            return self._latest_data

    def stop(self):
        self._running = False


if __name__ == '__main__':
    shanwan_gamepad = ShanWanGamepad()
    piracer = PiRacerStandard()


    gamepad_reader_thread = GamepadReader(shanwan_gamepad)
    gamepad_reader_thread.daemon = True 
    gamepad_reader_thread.start()


    gear_state = {
        'P': 1, 'D': 0, 'R': 0, 'N': 0
    }
    indicator_state = {
        'l': 0, 'r': 0
    }

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect(('localhost', 65432))

    except socket.error as e:
        gamepad_reader_thread.stop()
        GPIO.cleanup()
        exit(1) 

    try:
        previous_loop_time = time.time()
        while True:
            current_time = time.time()

            gamepad_input = gamepad_reader_thread.get_latest_data()
            if gamepad_input is None: 
                print("Warning: Gamepad data not yet available from thread, skipping this loop.")
                time.sleep(0.01) 
                continue


            x, y, a, b = gamepad_input.button_x, gamepad_input.button_y, gamepad_input.button_a, gamepad_input.button_b
            l, r = gamepad_input.button_l1, gamepad_input.button_r1

            throttle = gamepad_input.analog_stick_right.y * 0.5
            steering = -gamepad_input.analog_stick_left.x


            if x: gear_state = {'P': 1, 'D': 0, 'R': 0, 'N': 0}
            elif y: gear_state = {'P': 0, 'D': 1, 'R': 0, 'N': 0}
            elif a: gear_state = {'P': 0, 'D': 0, 'R': 1, 'N': 0}
            elif b: gear_state = {'P': 0, 'D': 0, 'R': 0, 'N': 1}

            if l:
                if indicator_state['l'] == 1: indicator_state['l'] = 0
                else: indicator_state['l'] = 1; indicator_state['r'] = 0
            if r:
                if indicator_state['r'] == 1: indicator_state['r'] = 0
                else: indicator_state['r'] = 1; indicator_state['l'] = 0
            

            if throttle < 0 or gear_state['P'] == 1 or gear_state['N'] == 1:
                throttle = 0
            if gear_state['R'] == 1 and throttle > 0:
                throttle = -throttle


            piracer.set_throttle_percent(throttle)
            piracer.set_steering_percent(steering)

            if current_time - start_time >= PERIOD:
                rpm = (counter / 20.0) * 60 / PERIOD
                speed = rpm * CIRCUMFERENCE * 100 / 60 # cm/s
                counter = 0
                start_time = current_time 
                
                new_distance = get_distance()
                if new_distance != -1.0: 
                    distance = new_distance
                else:
                    pass 
                
                print(f"Speed: {speed:.2f} cm/s, Distance: {distance:.2f} cm")

            control_data = create_control_data(throttle, steering, distance, speed, gear_state, indicator_state)
            print(f'data: throttle={throttle:.2f}, steering={steering:.2f} distance={distance:.2f}, speed={speed:.2f}, gear_state={gear_state}, indicator_state={indicator_state}')
            client_socket.sendall(control_data)


            elapsed_time_in_loop = time.time() - current_time
            sleep_duration = PERIOD - elapsed_time_in_loop
            if sleep_duration > 0:
                time.sleep(sleep_duration)
            previous_loop_time = current_time 

    except KeyboardInterrupt:
        print("사용자에 의해 차량 제어 중지됨.")

    finally:
        gamepad_reader_thread.stop() # 게임패드 스레드에 중지 요청
        gamepad_reader_thread.join() # 스레드가 완전히 종료될 때까지 대기
        GPIO.cleanup()
        client_socket.close()