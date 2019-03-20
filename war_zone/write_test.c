#include <stdio.h>
#include <unistd.h>

int main(void)
{
	dprintf(STDERR_FILENO, "Hello soon I seak by STDERR\n");
	return (0);
}
