#include <stdint.h>
#include <stdio.h>
extern "C"
{
#include <SDL.h>
}

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window*   window   = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

extern "C" {
	void render_pixel(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
	{
		//printf("[0] render_pixel(%u, {%u,%u,%u})\n", index, r, g, b);
		SDL_Rect fillRect = { (SCREEN_WIDTH / 40) * index, SCREEN_HEIGHT / 2, 15, 10};
		// Alpha might be useful for simulating low color on leds (since its not black).
		SDL_SetRenderDrawColor( renderer, r, g, b, 0xFF );
		SDL_RenderFillRect( renderer, &fillRect );
	}

	void show_pixels()
	{
		//printf("[0] show_pixels()\n");

		//Update screen
		SDL_RenderPresent( renderer );

		// Clear for next?
		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
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
