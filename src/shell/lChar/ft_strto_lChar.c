/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strTolChar.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:51 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

t_lChar		*ft_strto_lChar(const char *str)
{
	t_lChar		*begin_lst;
	t_lChar		*tmp;

	if ((begin_lst = ft_lCharnew(*str)) == NULL)
		return (NULL);
	tmp = begin_lst;
	str++;
	while (*str)
	{
		if ((tmp->next = ft_lCharnew(*str)) == NULL)
		{
			ft_lChardel_all(&begin_lst);
			return (NULL);
		}
		tmp->next->prev = tmp;
		tmp = tmp->next;
		str++;
	}
	return (begin_lst);
}
