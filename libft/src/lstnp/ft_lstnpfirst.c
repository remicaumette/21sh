/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnpfirst.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 17:32:07 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 17:32:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
