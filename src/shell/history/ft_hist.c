#include "history.h"

t_stackhist		*ft_hist(void)
{
	static t_stackhist		history = {0, NULL, NULL, NULL};

	return (&history);
}
