/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lCharPushBack.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:36 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:37 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

void		ft_lCharpush_front(t_lChar **begin_lst, t_lChar *node)
{
	if (*begin_lst != NULL)
	{
		(*begin_lst)->prev = node;
		node->next = *begin_lst;
	}
	*begin_lst = node;
}

void		ft_lCharpush_back(t_lChar **begin_lst, t_lChar *node)
{
	t_lChar		*tmp;

	if (*begin_lst == NULL)
	{
		*begin_lst = node;
		return ;
	}
	tmp = *begin_lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
