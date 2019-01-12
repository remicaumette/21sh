#include "lstnp.h"

/*
**	free one node
**
**	Parameters
**	----------
**	as : t_lstnp **
**		node to free
**	del : void (*)(void *)
**		function to del data
*/
void			ft_lstnpdel_one(t_lstnp **as, void (*del)(void *))
{
	t_lstnp		*tmp;

	tmp = *as;
	del(tmp->data);
	free(tmp);
	*as = NULL;
}
