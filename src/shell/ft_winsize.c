/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_winsize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:23:47 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 09:56:43 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

t_point		*ft_winsize(int action)
{
	static t_point		winsize = {-1, -1};
	t_point				tmp;

	if (action == 1)
	{
		if ((tmp.x = tgetnum(TC_NB_COL)) == -1)
			dprintf(1, "ft_critical(\"Fail get number of columns of terminal\", -1);");
		winsize.x = (size_t)tmp.x;
		if ((tmp.y = tgetnum(TC_NB_LINE)) == -1)
			dprintf(1, "ft_critical(\"Fail get number of line of terminal\", -1);");
		winsize.y = (size_t)tmp.y;
	}
	return (&winsize);
}

void		ft_winpos(t_point *pos)
{
	char		buf[10];
	int			ret;
	int			i;

	i = 0;
	ft_putstr(TC_GETPOS);
	if ((ret = read(0, buf, 10)) <= 0)
		return;
	buf[ret] = 0;
	pos->y = ft_atoi(&buf[2]);
	while (buf[i] && buf[i] != ';')
		i++;
	pos->x = ft_atoi(&buf[i]);
}
