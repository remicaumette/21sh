#include "shell.h"

void		shell_kill(t_shell *shell)
{
	static t_shell *save = NULL;

	if (shell)
		save = shell;
	else
	{
		if (save)
			save->kill = 1;
	}
}
