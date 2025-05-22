#include "../PiRacer/PiRacer.hpp"
#include "../Gamepad/ShanwanGamepad.hpp"

int main()
{
	// ==== pigpio 사전 설정 ====
    gpioCfgMemAlloc(PI_MEM_ALLOC_MAILBOX); // PAGEMAP → MAILBOX
    gpioCfgClock(PI_OFF);                  // mlock 비활성(안전망)

    int rc = gpioInitialise();
    if (rc < 0) {
        fprintf(stderr, "pigpio init failed (%d)\n", rc);
        return 1;
    }
    atexit(gpioTerminate);

	// Create instances
	PiRacer racer;
	ShanWanGamepad gamepad;

	while (true)
	{
		ShanWanGamepadInput input = gamepad.read_data();

		float steering = input.analog_stick_left.x;
		float throttle = input.analog_stick_right.y * 0.5; // limit throtle to 50%

		std::cout << "Throttle: " << throttle
				<< ", Steering: " << steering
				<< std::endl;
		
		racer.setSteeringPercent(steering);
		racer.setThrottlePercent(throttle);
	}

	return 0;
}