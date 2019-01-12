/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cursoradd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 13:39:05 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:39:06 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

int			ft_cursoradd(long buf, t_cursor *cursor)
{
	t_lChar		*tmp;

	if (buf >= 20 && buf <= 126)
	{
		if ((tmp = ft_lCharnew((char)buf)) == NULL)
			return (FAIL);
		ft_cursorinser(tmp, cursor);
		return (EGAIN);
	}
	else
		dprintf(1, "%c", (int)buf);
	return (EGAIN);
}
