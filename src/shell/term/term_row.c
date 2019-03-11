#include "shell.h"

int			term_row_start(t_shell *shell)
{
	if (tcsetattr(0, TCSANOW, shell->term->my) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		term_row_stop(t_shell *shell)
{
	if (action_str(TC_INSER_STOP) != SUCCESS)
		return (FAIL);
	if (tcsetattr(0, 0, shell->term->save) == -1)
		return (FAIL);
	return (SUCCESS);
}


