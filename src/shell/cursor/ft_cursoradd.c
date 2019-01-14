/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cursoradd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 13:39:05 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 11:34:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

int			ft_cursoradd(char buf, t_cursor *cursor)
{
	t_lChar		*tmp;

	if ((tmp = ft_lCharnew(buf)) == NULL)
		return (FAIL);
	ft_cursorinser(tmp, cursor);
	return (SUCCESS);
}
