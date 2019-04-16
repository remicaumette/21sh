/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_redirection.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 15:36:06 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 14:51:43 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	file_redirection(t_redirection *redir, t_process *process)
{
	if (redir->type == TOKEN_GREAT
			|| (redir->type == TOKEN_GREAT_2 && redir->symbols[0] == '1'))
		return (process_stdout_file(redir->file, O_TRUNC, process));
	if (redir->type == TOKEN_GREAT_2 && redir->symbols[0] == '2')
		return (process_stderr_file(redir->file, O_TRUNC, process));
	if (redir->type == TOKEN_DGREAT
			|| (redir->type == TOKEN_DGREAT_3 && redir->symbols[0] == '1'))
		return (process_stdout_file(redir->file, O_APPEND, process));
	if (redir->type == TOKEN_DGREAT_3 && redir->symbols[0] == '2')
		return (process_stderr_file(redir->file, O_APPEND, process));
	return (FAIL);
}

static int	dup_redirection(t_redirection *redir, t_process *process)
{
	if (redir->symbols[0] == '2')
	{
		process_stderr_dup(process->STDOUT, process);
		process->out_to_err = 0;
		return (SUCCESS);
	}
	if (redir->symbols[0] == '1')
	{
		process_stdout_dup(process->STDERR, process);
		process->out_to_err = 1;
		return (SUCCESS);
	}
	return (FAIL);
}

static int	close_redirection(t_redirection *redir, t_process *process)
{
	if (redir->symbols[0] == '0')
		return (process_stdin_close(process));
	if (redir->symbols[0] == '1' || redir->symbols[0] == '>')
		return (process_stdout_close(process));
	if (redir->symbols[0] == '2')
		return (process_stderr_close(process));
	return (FAIL);
}

int			eval_process_redirection(t_command *command, t_process *process,
		t_shell *shell)
{
	t_redirection		*tmp;

	tmp = command->redirection;
	while (tmp)
	{
		if (token_isfile_redir(tmp->type))
			file_redirection(tmp, process);
		if (tmp->type == TOKEN_GREATAND_4 || tmp->type == TOKEN_GREATAND_3_TIP)
			close_redirection(tmp, process);
		if (tmp->type == TOKEN_DLESS)
			eval_process_heredoc(tmp, process, shell);
		if (tmp->type == TOKEN_LESS)
			process_stdin_file(tmp->file, process);
		if (tmp->type == TOKEN_GREATAND_4_TIP)
			dup_redirection(tmp, process);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
