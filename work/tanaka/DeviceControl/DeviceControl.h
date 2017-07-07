#ifndef DeviceControl_h
#define DeviceControl_h
#include "arduino.h"

class Digital{
	public:
		static void pinMode(int pin, int mode);
		static void Write(int pin, int value);
		static int Read(int pin);
	private:
		Digital();
};

class Analog{
	public:
		static void Write(int pin, int value);
		static int Read(int pin);
	private:
		Analog();
};

#endif
