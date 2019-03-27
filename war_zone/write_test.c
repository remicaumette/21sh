#include <stdio.h>
#include <unistd.h>

int main(void)
{
	dprintf(STDOUT_FILENO, "Hello soon I speak by STDOUT\n");
	dprintf(STDERR_FILENO, "Hello soon I speak by STDERR\n");
	return (0);
}
