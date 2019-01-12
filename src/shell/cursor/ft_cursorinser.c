/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cursorinser.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 15:45:07 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:38:29 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

static inline void	inser_begin(t_lChar *new, t_cursor *cursor)
{
	new->next = cursor->first;
	cursor->first->prev = new;
	cursor->first = new;
	cursor->dist_first = 1;
}

static inline void	inser_end(t_lChar *new, t_cursor *cursor)
{
	new->prev = cursor->last;
	cursor->last->next = new;
	cursor->last = new;
	cursor->dist_first++;
	cursor->dist_last = -1;
}

static inline void	inser_mid(t_lChar *new, t_cursor *cursor)
{
	new->prev = cursor->current->prev;
	new->next = cursor->current;
	if (cursor->current->prev)
		cursor->current->prev->next = new;
	cursor->current->prev = new;
	cursor->dist_first++;
}

void				ft_cursorinser(t_lChar *new, t_cursor *cursor)
{
	if (cursor->first == NULL)
	{
		cursor->first = new;
		cursor->last = new;
		cursor->dist_first = 1;
		cursor->dist_last = -1;
	}
	else if (cursor->dist_last == -1)
		inser_end(new, cursor);
	else if (cursor->dist_first == 0)
		inser_begin(new, cursor);
	else
		inser_mid(new, cursor);
}
