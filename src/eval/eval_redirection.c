#include "eval.h"


static int	input_redirection(t_redirection *redirection, t_process *process)
{
	if (redirection->type == TOKEN_LESS)
		process_stdin_file(redirection->file, process);
	if (redirection->type == TOKEN_DLESS)
		dprintf(1, "TOKEN_DLESS: todo\n");
	if (redirection->type == TOKEN_LESSAND)
		dprintf(1, "TOKEN_LESSAND: todo\n");
	return (SUCCESS);
}

static int	output_redirection(t_redirection *redirection, t_process *process)
{
	int		flag;

	flag = 0;
	if (redirection->type == TOKEN_GREAT)
		flag = O_TRUNC;
	if (redirection->type == TOKEN_DGREAT)
		flag = O_APPEND;
	if (redirection->type == TOKEN_GREATAND)
		dprintf(1, "TOKEN_GREATAND: todo\n");
	return (process_stdout_file(redirection->file, flag, process));

}


int			eval_redirection(t_command *command, t_process *process)
{
	int					set_in;
	int					set_out;
	t_redirection		*tmp;

	set_in = 0;
	set_out = 0;
	tmp = command->redirection;
	while (tmp)
	{
		if (tmp->in)
		{
			set_in = 1;
			input_redirection(tmp, process);
		}
		if (tmp->out)
		{
			set_out = 1;
			output_redirection(tmp, process);
		}
		tmp = tmp->next;
	}
	if (!set_in)
		process_stdin_default(process);
	if (!set_out)
		process_stdout_default(process);
	return (SUCCESS);
}
