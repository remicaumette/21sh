#include "shell.h"

int		action_basic(t_line *line, char *buf, int readed)
{
	if (line_inser(line, *buf) != SUCCESS)
		return (FAIL);
	write(1, buf, readed);
	if (IS_ENDLINE)
	{
		if (!IS_LASTLINE)
			line->cur_pos.ws_row++;
		line->cur_pos.ws_col = 0;
	}
	else
		line->cur_pos.ws_col++;
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
