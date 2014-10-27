#include "Adafruit_NeoPixel.h"


SoftPixel::SoftPixel(uint16_t count, uint8_t pin, uint8_t mode)
{
	pixels = new uint32_t[count];

	printf("[?] Pixel(%d, %d, %d)\n", count, pin, mode);
}


void SoftPixel::begin(void)
{
	printf("[?] Pixel.begin\n");
}


void SoftPixel::show(void)
{
	printf("[!] Pixel.show\n");
}


uint32_t SoftPixel::Color(uint8_t r, uint8_t g, uint8_t b)
{
  	uint32_t color =	((uint32_t)r << 16) |
						((uint32_t)g <<  8) |
						((uint32_t)b <<  0);

	printf("[%%] Pixel.Color(%d, %d, %d) -> %X\n", r, g, b, color);

	return color;
}


uint32_t SoftPixel::getPixelColor(uint16_t position)
{
	uint32_t color = pixels[position];

	uint8_t r,g,b;

	r = (uint8_t)(color >> 16),
	g = (uint8_t)(color >>  8),
	b = (uint8_t)(color >>  0);

	printf("[R] Pixel.getPixelColor(%d) -> [%X, %d, %d, %d]\n", position, color, r, g, b);
	return color;
};


void SoftPixel::setPixelColor(uint16_t position, uint32_t color)
{
	pixels[position] = color;

	uint8_t r,g,b;

	r = (uint8_t)(color >> 16),
	g = (uint8_t)(color >>  8),
	b = (uint8_t)(color >>  0);

	printf("[W] Pixel.setPixelColor(%d, %X) -> [%d,%d,%d]\n", position, color, r, g, b);
}
