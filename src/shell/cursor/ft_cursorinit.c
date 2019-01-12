/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cursorinit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 13:39:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 14:02:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

void		ft_cursorinit(t_cursor *cursor)
{
	if (cursor == NULL)
		return ;
	ft_winpos(&(cursor->pos));
	cursor->winsize = ft_winsize(GET);
	cursor->current = NULL;
	cursor->first = NULL;
	cursor->last = NULL;
	cursor->dist_first = -1;
	cursor->dist_last = -1;
}
