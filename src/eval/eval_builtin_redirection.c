/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_builtin_redirection.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:33:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 14:54:31 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	file_redirection(t_redirection *redir, t_builtin *builtin)
{
	if (redir->type == TOKEN_GREAT
			|| (redir->type == TOKEN_GREAT_2 && redir->symbols[0] == '1'))
		return (builtin_stdout_file(redir->file, O_TRUNC, builtin));
	if (redir->type == TOKEN_GREAT_2 && redir->symbols[0] == '2')
		return (builtin_stderr_file(redir->file, O_TRUNC, builtin));
	if (redir->type == TOKEN_DGREAT
			|| (redir->type == TOKEN_DGREAT_3 && redir->symbols[0] == '1'))
		return (builtin_stdout_file(redir->file, O_APPEND, builtin));
	if (redir->type == TOKEN_DGREAT_3 && redir->symbols[0] == '2')
		return (builtin_stderr_file(redir->file, O_APPEND, builtin));
	return (FAIL);
}

static int	dup_redirection(t_redirection *redir, t_builtin *builtin)
{
	if (redir->symbols[0] == '2')
	{
		builtin_stderr_close(builtin);
		builtin->STDERR = builtin->STDOUT;
		return (SUCCESS);
	}
	if (redir->symbols[0] == '1')
	{
		builtin_stdout_close(builtin);
		builtin->STDOUT = builtin->STDERR;
		return (SUCCESS);
	}
	return (FAIL);
}

static int	close_redirection(t_redirection *redir, t_builtin *builtin)
{
	if (redir->symbols[0] == '0')
		return (builtin_stdin_close(builtin));
	if (redir->symbols[0] == '1' || redir->symbols[0] == '>')
		return (builtin_stdout_close(builtin));
	if (redir->symbols[0] == '2')
		return (builtin_stderr_close(builtin));
	return (FAIL);
}

int			eval_builtin_redirection(t_command *command, t_builtin *builtin,
			t_shell *shell)
{
	int					ret;
	t_redirection		*tmp;

	tmp = command->redirection;
	while (tmp && !shell->kill)
	{
		if (token_isfile_redir(tmp->type))
			ret = file_redirection(tmp, builtin);
		if (tmp->type == TOKEN_GREATAND_4 || tmp->type == TOKEN_GREATAND_3_TIP)
			close_redirection(tmp, builtin);
		if (tmp->type == TOKEN_DLESS)
			ret = eval_builtin_heredoc(tmp, builtin, shell);
		if (tmp->type == TOKEN_LESS)
			ret = builtin_stdin_file(tmp->file, builtin);
		if (tmp->type == TOKEN_GREATAND_4_TIP)
			ret = dup_redirection(tmp, builtin);
		if (ret != SUCCESS)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
