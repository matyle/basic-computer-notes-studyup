#include "csapp.h"

void end(void)
{
	printf("2");
}

int main(void)
{
	if (Fork() == 0)
		atexit(end);
	if (Fork() == 0)
		printf("0");
	else
		printf("1");
	exit(0);
}