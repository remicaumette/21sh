#include "eval.h"

/*
static int	input_redirection(t_redirection *redirection, t_process *process)
{
	dprintf(1, "input_redirection: TODO\n");
	return (SUCCESS);
	if (redirection->type == TOKEN_LESS)
		process_stdin(process->redirection->file);
	if (redirection->type == TOKEN_DLESS)
		dprintf(1, "TOKEN_DLESS: todo\n");
	if (redirection->type == TOKEN_LESSAND)
		dprintf(1, "TOKEN_LESSAND: todo\n");
}
*/
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
	if (command->redirection == NULL)
		return (process_stdall_default(process));
//	if (command->redirection->in)
//		input_redirection(command->redirection, process, shell);
	if (command->redirection->out)
		output_redirection(command->redirection, process);
	return (SUCCESS);
}
