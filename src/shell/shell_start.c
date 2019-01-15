/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_start.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:15:02 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:25:59 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	shell_readline(t_shell *shell)
{
	int		readed;
	char	buf[4];

	(void)shell;
	while ((readed = read(0, buf, 3)) > 0)
	{
		ft_bzero(buf + readed, 4 - readed);
		if (buf[0] == 4 && buf[1] == 0 && buf[2] == 0)
			break ;
	}
	return (0);
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
	return (shell_readline(shell));
}
