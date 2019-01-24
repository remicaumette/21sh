#include "shell.h"

int		action_debug(t_shell *shell)
{
	line_debug(shell->line);
	return (SUCCESS);
}
