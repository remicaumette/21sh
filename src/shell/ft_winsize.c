/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_winsize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:23:47 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 10:53:04 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			get_winsize(t_winsize *winsize)
{
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, winsize) == -1)
		return (FAIL);
	return (SUCCESS);
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
	buf[ret] = '\0';
	pos->y = ft_atoi(&buf[2]);
	while (buf[i] && buf[i] != ';')
		i++;
	pos->x = ft_atoi(&buf[i]);
}
