#include "shell.h"

t_stackhist		*hist(void)
{
	static t_stackhist		history = {0, NULL, NULL, NULL};

	return (&history);
}
