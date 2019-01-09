#include "shell.h"

int	shell_putchar(char c)
{
	return (write(1, &c, 1));
}
