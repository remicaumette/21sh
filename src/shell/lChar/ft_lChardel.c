/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lCharDel.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:32:04 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:32:08 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lChar.h"

static inline void		ft_lChardel(t_lChar **as)
{
	free(*as);
}

void					ft_lChardel_one(t_lChar **begin_lst, t_lChar **as)
{
	t_lChar		*tmp;


	if (*as == *begin_lst)
	{
		tmp = *begin_lst;
		*begin_lst = tmp->next;
		(*begin_lst)->prev = NULL;
	}
	else
	{
		tmp = *as;
		tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}
	ft_lChardel(as);
}

void				ft_lChardel_all(t_lChar **begin_lst_as)
{
	t_lChar		*tmp;
	t_lChar		*tmp_next;

	tmp = *begin_lst_as;
	while (tmp)
	{
		tmp_next = tmp->next;
		ft_lChardel(&tmp);
		tmp = tmp_next;
	}
	*begin_lst_as = NULL;
}
