/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnplast.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 17:32:12 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 17:33:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
**		last node of the list
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
