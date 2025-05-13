cmake_minimum_required(VERSION 3.15)
project(PiRacer-cpp VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pigpio REQUIRED)

include_directories(
	./Adafruit_INA219
	./Adafruit_PCA9685
	./Gamepad
	./PiRacer
	${pigpio_INCLUDE_DIRS}
)

set(PIRACER_SRC
	./Adafruit_INA219/Adafruit_INA219.cpp
	./Adafruit_PCA9685/Adafruit_PCA9685.cpp
	./PiRacer/PiRacer.cpp
)

set(GAMEPAD_SRC
	./Gamepad/Joystick.cpp
	./Gamepad/ShanwanGamepad.cpp
)


add_executable(gamepad_control
	./examples/gamepad_control.cpp
	${PIRACER_SRC}
	${GAMEPAD_SRC}
)
target_link_libraries(gamepad_control ${pigpio_LIBRARY})
