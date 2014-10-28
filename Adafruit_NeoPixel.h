#ifndef VirtualPixel_h
#define VirtualPixel_h

// Stripped down version for testing

#include <stdint.h>
#include <stdio.h>
#include "Arduino.h"

#define NEO_GRB     0x01
#define NEO_KHZ800  0x02

class SoftPixel
{
	public:
		SoftPixel(uint16_t, uint8_t=6, uint8_t=NEO_GRB + NEO_KHZ800);
		void begin(void);
		void show(void);

		uint32_t Color(uint8_t, uint8_t, uint8_t);
		uint32_t getPixelColor(uint16_t);
		void     setPixelColor(uint16_t, uint32_t);

	private:
		uint32_t* pixels;
		uint16_t  pixel_count;
};

typedef SoftPixel Adafruit_NeoPixel;

#endif
