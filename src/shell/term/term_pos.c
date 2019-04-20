/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term_size.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:40:50 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:40:54 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	feed_pos(char *buf, t_winsize *curent_pos)
{
	int		i;

	i = 0;
	while (buf[i] == '\n' || buf[i] == 27 || buf[i] == '[')
		i++;
	curent_pos->ws_row = ft_atous(&buf[i]);
	while (buf[i] != ';')
		i++;
	curent_pos->ws_col = ft_atous(&buf[++i]);
}

int			term_getcurentpos(t_winsize *curent_pos)
{
	char	buf[32];
	size_t	i;

	i = 0;
	ft_putstr(TC_GETCURSOR);
	while (i < sizeof(buf) - 1)
	{
		if (read(0, buf + i, 1) != 1)
			break ;
		if (buf[i] == 'R')
			break ;
		i++;
	}
	buf[i] = '\0';
	feed_pos(buf, curent_pos);
	return (SUCCESS);
}
