/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_start.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:15:02 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:14:57 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	shell_stop(int status)
{
	char			*tmp;
	struct termios	term;

	if ((tmp = tgetstr("ei", NULL)) == NULL)
		return (1);
	ft_putstr(tmp);
	if (tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);
	return (status);
}

static int	shell_readline(t_shell *shell)
{
	int		readed;
	long	buf;

	buf = 0;
	if (shell_prompt(shell) != SUCCESS)
		return (shell_stop(1));
	if (window_getcurentpos(&(shell->line->cur_pos)) != SUCCESS)
		return (shell_stop(1));
	while ((readed = read(0, &buf, sizeof(buf))) > 0)
	{
		if (shell_actiondispatcher(shell, buf))
			return (shell_stop(1));
		buf = 0;
	}
	return (shell_stop(0));
}

int			shell_start(t_shell *shell)
{
	struct termios	term;

	if (tgetent(NULL, shell_getenv(shell, "TERM")) == -1 ||
		tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (1);
	window_resize(shell);
	init_signal();
	return (shell_readline(shell));
}
