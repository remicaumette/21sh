/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lCharNew.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:30 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:31 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

t_lChar			*ft_lCharnew(char c)
{
	t_lChar		*out;

	if ((out = malloc(sizeof(out))) == NULL)
		return (NULL);
	out->c = c;
	out->next = NULL;
	out->prev = NULL;
	return out;
}
