/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_heredoc.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:26 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 14:06:43 by timfuzea    ###    #+. /#+    ###.fr     */
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
	process->STDIN = fdpipe[0];
	while ((ret = SUCCESS))
	{
		line_reset(shell->line);
		ft_putstr("heredoc> ");
		while ((ret = shell_getline(shell)) == RET_STOP && !shell->kill)
			;
		if (ret == FAIL || shell->kill == 1)
		{
			shell->kill_str = ft_strdup(shell->line->content);
			ret = FAIL;
			break ;
		}
		if (ft_strequ(shell->line->content, redirection->file) == 1)
			break ;
		ft_putendl_fd(shell->line->content, fdpipe[1]);
	}
	line_reset(shell->line);
	close(fdpipe[1]);
	return (ret);
}

int			eval_builtin_heredoc(t_redirection *redirection, t_builtin *builtin,
		t_shell *shell)
{
	int			ret;
	int			fdpipe[2];

	if (pipe(fdpipe) != 0)
		return (FAIL);
	builtin->STDIN = fdpipe[0];
	while ((ret = SUCCESS))
	{
		line_reset(shell->line);
		ft_putstr("heredoc> ");
		while ((ret = shell_getline(shell)) == RET_STOP && !shell->kill)
			;
		if (ret == FAIL || !shell->kill)
		{
			shell->kill_str = ft_strdup(shell->line->content);
			ret = FAIL;
			break ;
		}
		if (ft_strequ(shell->line->content, redirection->file) == 1)
			break ;
		ft_putendl_fd(shell->line->content, fdpipe[1]);
	}
	line_reset(shell->line);
	close(fdpipe[1]);
	return (ret);
}
