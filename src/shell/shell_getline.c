#include "shell.h"

t_ret		shell_getline(t_shell *shell)
{
	int		readed;
	t_ret	ret;
	long	buf;

	buf = 0;
	while ((readed = read(0, &buf, sizeof(buf))) > 0)
	{
		if ((ret = action_dispatcher(shell, buf)) != RET_EGAIN)
			break;
		buf = 0;
	}
	return (ret);
}
