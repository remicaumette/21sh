#include "lstnp.h"

/*
**	return first node form the list containe node
**
**	Parameters
**	----------
**	node : t_lstnp *
**		node form list
**
**	Returns
**	-------
**	node : t_lstnp
**		first node of the list
*/

t_lstnp		*ft_lstnpfirst(t_lstnp *node)
{
	if (node)
	{
		while (node->prev)
			node = node->prev;
	}
	return (node);
}
