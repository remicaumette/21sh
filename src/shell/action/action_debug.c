#include "shell.h"

# ifdef USE_DEBUG

int		action_debug(t_shell *shell)
{
	line_debug(shell->line);
	return (SUCCESS);
}
#endif
