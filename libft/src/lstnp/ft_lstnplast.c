#include "lstnp.h"

/*
**	Parametres
**	----------
**	node : t_lstnp *
**		node from lstnp
**
**	Returns
**	-------
**	t_lstnp :
		last node of the list
*/

t_lstnp		*lstnplast(t_lstnp *node)
{
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	return (node);
}
