#include "libft.h"

char		**ft_strarr_new(size_t size)
{
	char	**out;

	if (!(out = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (size)
	{
		out[size] = NULL;
		size--;
	}
	*out = NULL;
	return (out);
}
