/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lCharTostr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:45 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:48 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

char		*ft_lCharto_str(t_lChar *node)
{
	char		*out;
	char		*pt_out;
	size_t		len;

	len = ft_lCharlen(node);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	pt_out = out;
	while (node)
	{
		*pt_out = node->c;
		node = node->next;
		pt_out++;
	}
	*pt_out = '\0';
	return out;
}
