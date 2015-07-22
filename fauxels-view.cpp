#include <stdint.h>
#include <stdio.h>
extern "C"
{
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
}

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window*   window   = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

// List of leds per view and of view sizes
uint8_t fauxel_leds [256] = {0};
uint8_t fauxel_views[256] = {0};
uint8_t fauxel_view_count = 0;

extern "C" {
	void register_view(uint8_t start, uint8_t length)
	{
		// Track instances and assign leds to each view once.
		// TODO use static lists on the view classes.
		fauxel_view_count++;
		fauxel_views[fauxel_view_count] = length;

		for(int i = start; i < start + length; i++)
		{
			if(fauxel_leds[i] == 0)
			{
				fauxel_leds[i] = fauxel_view_count;
			}
		}
	}

	void render_pixel(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
	{
		//printf("[0] render_pixel(%u, {%u,%u,%u})\n", index, r, g, b);

		uint8_t view = fauxel_leds[index];
		uint8_t view_size = fauxel_views[view];

		uint16_t x = SCREEN_WIDTH / 40 * index;
		uint16_t y = SCREEN_HEIGHT / 2;
		uint8_t radius = 15;
		filledCircleRGBA( renderer, x, y, radius, r, g, b, 0xFF );
		// Alpha might be useful for simulating low color on leds (since its not black).
		// Could also draw overlapping alpha shapes since leds are individual colors.
		//SDL_SetRenderDrawColor( renderer, r, g, b, 0xFF );
		//SDL_Rect fillRect = { (SCREEN_WIDTH / 40) * index, SCREEN_HEIGHT / 2, 15, 15};
		//SDL_RenderFillRect( renderer, &fillRect );
	}

	// TODO drawing loop could be handled here instead of per pixel. Just need a local copy of the color buffer as each color is set
	void show_pixels()
	{
		//printf("[0] show_pixels()\n");

		//Update screen
		SDL_RenderPresent( renderer );

		// Clear for next?
		SDL_SetRenderDrawColor( renderer, 0x10, 0x10, 0x10, 0xFF );
		SDL_RenderClear( renderer );

		// Clear out events
		while( SDL_PollEvent( &event ) != 0 )
		{
			if( event.type == SDL_QUIT )
			{
				exit(0);
			}
		}
	}

	void initialize_pixels(uint16_t count)
	{
		printf("[0] initialize_pixels(%d)\n", count);

		SDL_Init( SDL_INIT_VIDEO );
		window = SDL_CreateWindow( "fauxel pixels", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( renderer );
		SDL_RenderPresent( renderer );
	}
}
