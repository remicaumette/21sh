/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnpdel_one.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 17:30:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 17:32:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
