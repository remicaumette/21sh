/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cursordel_current.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 13:38:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:38:03 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

static inline void		del_first(t_cursor *cursor)
{
	t_lChar		*tmp;

	tmp = cursor->current->next;
	tmp->prev = NULL;
	free(cursor->current);
	cursor->current = tmp;
	cursor->dist_last--;
}

static inline void		del_last(t_cursor *cursor)
{
	t_lChar		*tmp;

	tmp = cursor->last->prev;
	if (tmp)
		tmp->next = NULL;
	free(cursor->last);
	cursor->last = tmp;
	cursor->dist_first--;
}

static inline void		del_mid(t_cursor *cursor)
{
	t_lChar		*tmp;

	tmp = cursor->current->prev->prev;
	free(cursor->current->prev);
	cursor->current->prev = tmp;
	tmp->next = cursor->current;
	cursor->dist_first--;
}

void					ft_cursordel_current(t_cursor *cursor)
{
	if (cursor->dist_first == 1 && cursor->dist_last == -1)
	{
		free(cursor->last);
		cursor->last = NULL;
		cursor->first = NULL;
		cursor->dist_last = -1;
		cursor->dist_first = -1;
	}
	else if (cursor->dist_last == -1)
		del_last(cursor);
	else if (cursor->dist_first == 0)
		del_first(cursor);
	else
		del_mid(cursor);
}
