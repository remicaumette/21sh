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

static int	reset_printed_line(t_shell *shell)
{
	int				tmp_cursor;

	tmp_cursor = CURSOR;
	while (tmp_cursor > 1)
	{
		if (action_move_left(shell) != SUCCESS)
			return (FAIL);
		tmp_cursor--;
	}
	if (action_str(TC_CLEAR_TO_END) != SUCCESS)
		return (FAIL);
	ft_putstr(shell->line->content);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &(shell->line->window));
	term_getcurentpos(&(shell->line->cur_pos));
	tmp_cursor = shell->line->size - CURSOR;
	while (tmp_cursor > 1)
	{
		if (action_move_left(shell) != SUCCESS)
			return (FAIL);
		tmp_cursor--;
	}
	return (SUCCESS);
}

int			term_getcurentpos(t_winsize *curent_pos)
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
		return (FAIL);
	curent_pos->ws_col = ft_atous(&buf[++i]);
	return (SUCCESS);
}

void		term_resize(t_shell *shell)
{
	static	t_shell		*shell_save = NULL;
	static int			lock = 0;

	if (lock == 1)
	{
		while (lock)
			continue;
	}
	lock = 1;
	if (shell_save == NULL && shell)
	{
		shell_save = shell;
		reset_printed_line(shell_save);
	}
	if (!shell)
		reset_printed_line(shell_save);
	lock = 0;
}
