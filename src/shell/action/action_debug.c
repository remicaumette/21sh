#include "shell.h"

# ifdef USE_DEBUG

t_ret		action_debug(t_shell *shell)
{
	line_debug(shell->line);
	return (RET_EGAIN);
}
#endif
