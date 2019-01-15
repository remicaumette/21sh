/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cursorinit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 13:39:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 11:04:21 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

void		ft_cursorinit(t_cursor *cursor)
{
	if (cursor == NULL)
		return ;
	ft_winpos(&(cursor->pos));
	get_winsize(&cursor->winsize);
	cursor->current = NULL;
	cursor->first = NULL;
	cursor->last = NULL;
	cursor->dist_first = -1;
	cursor->dist_last = -1;
}
