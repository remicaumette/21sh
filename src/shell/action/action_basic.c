#include "shell.h"

int		action_basic(t_shell *shell, char *buf, int readed)
{
	if (line_inser(shell->line, *buf) != SUCCESS)
		return (FAIL);
	write(1, buf, readed);
	return (SUCCESS);
}
/*
int		action_basic(t_shell *shell, char *buf, int readed)
{
	dprintf(1, "readed=%d\t{%d, %d, %d}, {%c, %c, %c}\n", readed, buf[0], buf[1], buf[2], buf[0], buf[1], buf[2]);
	if (line_inser(shell->line, *buf) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}*/
