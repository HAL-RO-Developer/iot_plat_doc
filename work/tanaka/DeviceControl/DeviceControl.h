#ifndef DeviceControl_h
#define DeviceControl_h
#include "arduino.h"
#include <Wire.h>

class Digital{
	public:
		static void SetMode(int pin, int mode);
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

class I2C{
	public: 
		static void begin(int address);
		static int reqFrom(int address, int count);
		static void beginTransmission(int address);
		static int endTransmission();
		static int Write(int value);
		static int Write(char* string);
		static int Read();
		static int available();
	private:
		I2C();
};

#endif
