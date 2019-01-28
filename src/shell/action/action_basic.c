#include "shell.h"

static int		multi_line(t_line *line)
{
	int		i;

	i = -1;
	if (action_str(TC_INSER_STOP) != SUCCESS)
		return (FAIL);
	ft_putstr(&(line->content[line->cursor - 2]));
	line_curpp(line, line->size - line->cursor + 2);
	while (++i <= (line->size - line->cursor))
	{
		if (action_move_left(line) != SUCCESS)
			return (FAIL);
	}
	if (action_str(TC_INSER_START) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int				action_basic(t_line *line, char *buf, int readed)
{
	if (line_inser(line, *buf) != SUCCESS)
		return (FAIL);
	if (((line->size >= line->window.ws_col) && (line->size / line->window.ws_col) > (line->cursor / line->window.ws_col)))
	{
		if (multi_line(line) != SUCCESS)
			return (FAIL);
	}
	else
	{
		write(1, buf, readed);
		if (IS_ENDLINE)
		{
			if (!IS_LASTLINE)
				line->cur_pos.ws_row++;
			line->cur_pos.ws_col = 1;
		}
		else
			line->cur_pos.ws_col++;
	}
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
