/* Simplified arduino methods for desktop testing */

#include "Arduino.h"


void pinMode(uint8_t pin, uint8_t mode)
{
	printf("[?] pinMode(%d, %d)\n", pin, mode);
}


void digitalWrite(uint8_t pin, uint8_t value)
{
	printf("[>] pinWrite(%d, %d)\n", pin, value);
}


int digitalRead(uint8_t pin)
{
	int value = 0;
	printf("[<] digitalRead(%d) -> %d\n", pin, value);
	return value;
}


void delay(unsigned long milliseconds)
{
	printf("[!] delay(%lu)\n", milliseconds);
	usleep(milliseconds * 1000);
}
