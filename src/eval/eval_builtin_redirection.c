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
	else
		dprintf(1, "Debug redirection=>type: %d\n", redir->type);
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
	else
		dprintf(1, "Debug redirection=>type: %d\n", redir->type);
	return (FAIL);
}

int			eval_builtin_redirection(t_command *command, t_builtin *builtin, t_shell *shell)
{
	t_redirection		*tmp;

	tmp = command->redirection;
	while (tmp)
	{
		if (token_isfile_redir(tmp->type))
			file_redirection(tmp, builtin);
		if (tmp->type == TOKEN_GREATAND_4 || tmp->type == TOKEN_GREATAND_3_TIP)
			close_redirection(tmp, builtin);
		if (tmp->type == TOKEN_DLESS)
			eval_builtin_heredoc(tmp, builtin, shell); // !!! ???
		if (tmp->type == TOKEN_LESS)
			builtin_stdin_file(tmp->file, builtin);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
