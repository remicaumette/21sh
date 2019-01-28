/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 13:25:21 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 13:41:24 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "debug.h"

int			window_getcurentpos(t_winsize *curent_pos)
{
	char	buf[10 + 1];
	int		ret;
	int		i;

	i = 3;
	ft_putstr(TC_GETCURSOR);
	if ((ret = read(STDIN_FILENO, &buf, 10)) <= 0)
		return (FAIL);
	buf[ret] = '\0';
	curent_pos->ws_row = ft_atous(&buf[2]);
	while (buf[i] && buf[i] != ';')
		i++;
	if (!buf[i])
	{
		dprintf(1, "fail de conseption need rewite sone code\n"); // remove after many many test
		return (FAIL);
	}
	curent_pos->ws_col = ft_atous(&buf[++i]);
	return (SUCCESS);
}

void		window_resize(t_shell *shell)
{
	static	t_shell		*shell_save = NULL;

	if (shell_save == NULL && shell)
		shell_save = shell;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &(shell_save->line->window));
	window_getcurentpos(&(shell_save->line->cur_pos));
}


