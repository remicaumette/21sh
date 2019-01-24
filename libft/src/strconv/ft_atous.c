
#include "libft.h"

unsigned short		ft_atous(const char *s)
{
	unsigned short	r;

	r = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + (*s++ - '0');
	return (r);
}
