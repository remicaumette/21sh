#include "libft.h"

char		*ft_strjoinfree(char **s1, char **s2, int i)
{
	char		*tmp;

	tmp = ft_strjoin(*s1, *s2);
	if (i == 1 || i == 3)
		ft_strdel(s1);
	if (i == 2 || i == 3)
		ft_strdel(s2);
	return (tmp);
}
