#include <stdio.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#include "sketch/sketch.ino"

int main(int argc, char *argv[])
{
	printf("Starting virtuino.\n");

	setup();

#ifdef EMSCRIPTEN
	  emscripten_set_main_loop(loop, 0, 1); // 0 fps = as fast as possible, 3rd arg 1 = simulate infinite loop
#else
	for (;;)
	{
		loop();
	}
#endif

	return 0;
}
