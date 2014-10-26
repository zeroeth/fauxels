#include <stdio.h>

extern void setup();
extern void loop();

int main(int argc, char *argv[])
{
	printf("Starting virtuino.\n");

	setup();

	for (;;)
	{
		loop();
	}

	return 0;
}
