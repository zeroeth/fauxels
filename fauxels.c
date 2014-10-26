#include <stdio.h>

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
