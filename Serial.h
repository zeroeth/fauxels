#ifndef Virtuino_Serial_h
#define Virtuino_Serial_h

#include <stdio.h>

class PrintfSerial
{
	public:
		PrintfSerial();
		void begin(unsigned long);
		size_t print(const char[]);
		size_t print(int);
		size_t print(unsigned int);
		size_t print(long);
		size_t print(unsigned long);
		size_t print(double);
}

extern PrintfSerial Serial;

#endif
