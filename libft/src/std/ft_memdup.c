#include "libft.h"

void		*ft_memdup(const void *mem, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		return (NULL);
	ft_memcpy(tmp, mem, size);
	return (tmp);
}
