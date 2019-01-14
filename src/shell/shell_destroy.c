/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_destroy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:18:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 13:35:47 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	exit_line(void)
{
	char			*tmp;
	struct	termios		term;

	if ((tmp = tgetstr(TC_INSER_STOP, NULL)) == NULL)
		return ;
	ft_putstr(tmp);
	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);
}

void	shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->environment)
			ft_strarr_del(shell->environment);
		if (shell->line)
			ft_strdel(&shell->line);
		if (shell->history)
			ft_strarr_del(shell->history);
		if (shell->lexer)
			lexer_destroy(shell->lexer);
		if (shell->parser)
			parser_destroy(shell->parser);
		ft_memdel((void **)&shell);
	}
	exit_line();
}
