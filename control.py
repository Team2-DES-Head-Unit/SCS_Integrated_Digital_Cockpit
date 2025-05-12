import socket
import struct
import RPi.GPIO as GPIO
import time
import threading
from piracer.vehicles import PiRacerStandard
from piracer.gamepads import ShanWanGamepad


ENCODER_PIN = 17
TRIG_PIN = 24
ECHO_PIN = 23

CIRCUMFERENCE = 0.214  # 바퀴의 원주 (미터)
PERIOD = 0.1           # 측정 주기 (초)

counter = 0
speed = 0.0
distance = 0.0

GPIO.setmode(GPIO.BCM)
GPIO.setup(ENCODER_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)

# 기본 기어 상태
gear_state = {'P': 1, 'D': 0, 'R': 0, 'N': 0}
indicator_state = {'l': 0, 'r': 0}

# PiRacer 초기화
piracer = PiRacerStandard()
shanwan_gamepad = ShanWanGamepad()

# 인터럽트 설정
def count(channel):
    global counter
    counter += 1

GPIO.add_event_detect(ENCODER_PIN, GPIO.RISING, callback=count)

# 거리 측정
def get_distance():
    GPIO.output(TRIG_PIN, GPIO.HIGH)
    time.sleep(0.000015)  
    GPIO.output(TRIG_PIN, GPIO.LOW)
    
    start = time.time()
    while GPIO.input(ECHO_PIN) == GPIO.LOW:
        start = time.time()
    
    while GPIO.input(ECHO_PIN) == GPIO.HIGH:
        end = time.time()
    
    duration = end - start
    return round((340.0 * duration) / 2 * 100, 2)

# ControlData 생성
def create_control_data(throttle, steering, speed, distance, gear_state, indicator_state):
    return struct.pack(
        'ffffBBBBBB',  # 4개의 float (throttle, steering, speed, distance) + 6개의 uint8_t
        throttle, steering, speed, distance,
        gear_state['P'], gear_state['D'], gear_state['R'], gear_state['N'],
        indicator_state['l'], indicator_state['r']
    )


def calculate_speed_distance():
    global counter, speed, distance
    start_time = time.time()

    while True:
        if time.time() - start_time >= PERIOD:

            rpm = (counter / 20.0) * 60 / PERIOD
            speed = rpm * CIRCUMFERENCE * 100 / 60
            counter = 0
            start_time = time.time()

            distance = get_distance()


def handle_gamepad(client_socket):
    global gear_state, indicator_state
    try:
        while True:
            gamepad_input = shanwan_gamepad.read_data()
            x, y, a, b, l, r = gamepad_input.button_x, gamepad_input.button_y, gamepad_input.button_a, gamepad_input.button_b, gamepad_input.button_l1, gamepad_input.button_r1

            # 기어 변경
            if x:
                gear_state = {'P': 1, 'D': 0, 'R': 0, 'N': 0}
            elif y:
                gear_state = {'P': 0, 'D': 1, 'R': 0, 'N': 0}
            elif a:
                gear_state = {'P': 0, 'D': 0, 'R': 1, 'N': 0}
            elif b:
                gear_state = {'P': 0, 'D': 0, 'R': 0, 'N': 1}

            # 방향 지시등
            if l:
                if indicator_state['l'] == 1:
                    indicator_state['l'] = 0
                else:
                    indicator_state['l'] = 1
                    indicator_state['r'] = 0

            if r:
                if indicator_state['r'] == 1:
                    indicator_state['r'] = 0
                else:
                    indicator_state['r'] = 1
                    indicator_state['l'] = 0


            throttle = gamepad_input.analog_stick_right.y * 0.5
            steering = -gamepad_input.analog_stick_left.x


            if throttle < 0 or gear_state['P'] == 1 or gear_state['N'] == 1:
                throttle = 0

            if gear_state['R'] == 1 and throttle > 0:
                throttle = -throttle


            piracer.set_throttle_percent(-throttle)
            piracer.set_steering_percent(steering)

            control_data = create_control_data(throttle, steering, speed, distance, gear_state, indicator_state)
            client_socket.sendall(control_data)

            print(f"Throttle: {throttle:.2f}, Steering: {steering:.2f}, Speed: {speed:.2f} cm/s, Distance: {distance:.2f} cm")
            print(gear_state, indicator_state)

            time.sleep(0.05)

    except KeyboardInterrupt:
        print("\nVehicle control stopped by user")
    finally:
        client_socket.close()

try:

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 65432))
    print("Connected to C++ server")

    speed_thread = threading.Thread(target=calculate_speed_distance)
    speed_thread.daemon = True
    speed_thread.start()

    handle_gamepad(client_socket)

except KeyboardInterrupt:
    print("\nExiting...")
finally:
    GPIO.cleanup()
    client_socket.close()
