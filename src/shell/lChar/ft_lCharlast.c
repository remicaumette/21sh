/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lCharLast.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:16 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

t_lChar		*ft_lChatlast(t_lChar *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
}
