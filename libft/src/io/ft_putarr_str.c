#include "io.h"

void		ft_putarr_str(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr);
		ft_putchar('\n');
		arr++;
	}
}
