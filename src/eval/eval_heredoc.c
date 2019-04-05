/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_heredoc.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:26 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 18:19:04 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			eval_process_heredoc(t_redirection *redirection, t_process *process,
		t_shell *shell)
{
	int			ret;
	int			fdpipe[2];

	if (pipe(fdpipe) != 0)
		return (FAIL);
	ret = SUCCESS;
	process->std[STDIN] = fdpipe[STDIN];
	while (101)
	{
		line_reset(shell->line);
		ft_putstr("heredoc> ");
		if (shell_getline(shell) == RET_FAIL)
		{
			ret = FAIL;
			break ;
		}
		if (ft_strequ(shell->line->content, redirection->file) == 1)
			break ;
		ft_putendl_fd(shell->line->content, fdpipe[STDOUT]);
	}
	line_reset(shell->line);
	close(fdpipe[STDOUT]);
	process->isset[STDIN] = 1;
	return (ret);
}

int			eval_builtin_heredoc(t_redirection *redirection, t_builtin *builtin,
		t_shell *shell)
{
	int			ret;
	int			fdpipe[2];

	if (pipe(fdpipe) != 0)
		return (FAIL);
	ret = SUCCESS;
	builtin->std[STDIN] = fdpipe[STDIN];
	while (101)
	{
		line_reset(shell->line);
		ft_putstr("heredoc> ");
		if (shell_getline(shell) == RET_FAIL)
		{
			ret = FAIL;
			break ;
		}
		if (ft_strequ(shell->line->content, redirection->file) == 1)
			break ;
		ft_putendl_fd(shell->line->content, fdpipe[STDOUT]);
	}
	line_reset(shell->line);
	close(fdpipe[STDOUT]);
	builtin->isset[STDIN] = 1;
	return (ret);
}
