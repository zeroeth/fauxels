#include "Adafruit_NeoPixel.h"

extern "C" {
  extern void render_pixel(uint16_t, uint8_t, uint8_t, uint8_t);
  extern void initialize_pixels(uint16_t);
  extern void show_pixels();
}

SoftPixel::SoftPixel(uint16_t count, uint8_t pin, uint8_t mode)
{
	pixels = new uint32_t[count];
	pixel_count = count;

	//printf("[?] Pixel(%d, %d, %d)\n", count, pin, mode);

	initialize_pixels(count); // TODO also initialize views to show overlap
}


void SoftPixel::begin(void)
{
	//printf("[?] Pixel.begin\n");
}


void SoftPixel::show(void)
{
	//printf("[!] Pixel.show\n");
	show_pixels();

	for(int i = 0; i < pixel_count; i++)
	{
		uint8_t r,g,b;

		r = (uint8_t)(pixels[i] >> 16),
		g = (uint8_t)(pixels[i] >>  8),
		b = (uint8_t)(pixels[i] >>  0);

		render_pixel(i, r, g, b); // Implement in sdl/gl/canvas
	}
}


uint32_t SoftPixel::Color(uint8_t r, uint8_t g, uint8_t b)
{
  	uint32_t color =	((uint32_t)r << 16) |
						((uint32_t)g <<  8) |
						((uint32_t)b <<  0);

	//printf("[%%] Pixel.Color(%d, %d, %d) -> %X\n", r, g, b, color);

	return color;
}


uint32_t SoftPixel::getPixelColor(uint16_t position)
{
	uint32_t color = pixels[position];

	/*
	 uint8_t r,g,b;

	r = (uint8_t)(color >> 16),
	g = (uint8_t)(color >>  8),
	b = (uint8_t)(color >>  0);
	*/
	//printf("[R] Pixel.getPixelColor(%d) -> [%X, %d, %d, %d]\n", position, color, r, g, b);
	return color;
};


void SoftPixel::setPixelColor(uint16_t position, uint32_t color)
{
	pixels[position] = color;

	uint8_t r,g,b;

	r = (uint8_t)(color >> 16),
	g = (uint8_t)(color >>  8),
	b = (uint8_t)(color >>  0);

	//printf("[W] Pixel.setPixelColor(%d, %X) -> [%d,%d,%d]\n", position, color, r, g, b);
}
