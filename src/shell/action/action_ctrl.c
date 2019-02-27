#include "shell.h"

int		action_ctrl_up(t_shell *shell)
{
	int		i;

	i = MAX_COL;
	if ((CURSOR - MAX_COL) > 0)
	{
		while (i)
		{
			if (action_move_left(shell) != SUCCESS)
				return (FAIL);
			i--;
		}
		CURSOR -= MAX_COL;
	}
	return (SUCCESS);
}

int		action_ctrl_down(t_shell *shell)
{
	int		i;

	i = MAX_COL;
	if ((CURSOR + MAX_COL) < (shell->line->size + 2))
	{
		while (i)
		{
			if (action_move_right(shell) != SUCCESS)
				return (FAIL);
			i--;
		}
		CURSOR += MAX_COL;
	}
	return (SUCCESS);
}