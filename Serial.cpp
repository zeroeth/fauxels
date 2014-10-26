#include "Serial.h"

void PrintfSerial::begin(unsigned long value)
{
	printf("[?] Serial.begin(%lu)\n", value);
}

size_t PrintfSerial::print(const char value[])
{
	printf("[W] Serial.print(\"%s\")\n", value);
	return 0;
}

size_t PrintfSerial::print(int value)
{
	printf("[W] Serial.print(%d)\n", value);
	return 0;
}

size_t PrintfSerial::print(unsigned int value)
{
	printf("[W] Serial.print(%u)\n", value);
	return 0;
}

size_t PrintfSerial::print(long value)
{
	printf("[W] Serial.print(%l)\n", value);
	return 0;
}

size_t PrintfSerial::print(unsigned long value)
{
	printf("[W] Serial.print(%lu)\n", value);
	return 0;
}

size_t PrintfSerial::print(double value)
{
	printf("[W] Serial.print(%f)\n", value);
	return 0;
}

PrintfSerial Serial;
