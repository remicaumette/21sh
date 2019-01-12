#include "lstnp.h"

/*
**	malloc new node for a list lstnp
**
**	Parameters
**	----------
**	data : void *
**
**	Returns
**	-------
**	t_lstnp :
**		->data = data
**		->next = NULL;
**		->prev = NULL;
*/
t_lstnp		*ft_lstnpnew(void *data)
{
	t_lstnp			*new;

	if ((new = malloc(sizeof(new))) == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
