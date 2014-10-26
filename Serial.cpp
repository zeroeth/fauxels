#include "Serial.h"

PrintfSerial::PrintfSerial()
{

}


size_t PrintfSerial::print(const char value[])
{
	printf("[W] print(%s)\n", value);
	return 0;
}

size_t print(int value);
{
	printf("[W] print(%d)\n", value);
	return 0;
}
size_t print(unsigned int value);
{
	printf("[W] print(%u)\n", value);
	return 0;
}

size_t print(long value);
{
	printf("[W] print(%l)\n", value);
	return 0;
}

size_t print(unsigned long value)
{
	printf("[W] print(%lu)\n", value);
	return 0;
}

size_t print(double value)
{
	printf("[W] print(%f)\n", value);
	return 0;
}

PrintfSerial Serial();
