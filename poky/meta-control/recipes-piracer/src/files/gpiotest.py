import RPi.GPIO as GPIO
import time


ENCODER_PIN = 17
TRIG_PIN = 24
ECHO_PIN = 23

CIRCUMFERENCE = 0.214  # 바퀴의 원주 (미터)
PERIOD = 0.1           # 측정 주기 (초)

counter = 0
start_time = time.time()

GPIO.setmode(GPIO.BCM)
GPIO.setup(ENCODER_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)

def count(channel):
    global counter
    counter += 1

GPIO.add_event_detect(ENCODER_PIN, GPIO.RISING, callback=count)

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
    

    distance = (340.0 * duration) / 2 * 100
    return round(distance, 2)

try:
    while True:
        if time.time() - start_time >= PERIOD:

            rpm = (counter / 20.0) * 60 / PERIOD
            speed = rpm * CIRCUMFERENCE * 100 / 60
            

            counter = 0
            start_time = time.time()
            
            distance = get_distance()
            
            print(f"Speed: {speed:.2f} cm/s, Distance: {distance:.2f} cm")

except KeyboardInterrupt:
    print("\nExiting...")
finally:
    GPIO.cleanup()
