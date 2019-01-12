/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lCharFirst.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:12 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

t_lChar		*ft_lCharfirst(t_lChar *node)
{
	if (node != NULL)
		while (node->prev)
			node = node->prev;
	return node;
}
