/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnpnew.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 17:32:26 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 17:32:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
