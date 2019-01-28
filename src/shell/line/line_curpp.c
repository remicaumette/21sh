#include "shell.h"

int		line_curpp(t_line *line, int n)
{
	if (n <= 0)
		return (FAIL);
	while (n > 0)
	{
		if (!IS_ENDLINE)
			line->cur_pos.ws_col++;
		else
		{
			line->cur_pos.ws_col = 1;
			if (!IS_LASTLINE)
				line->cur_pos.ws_row++;
		}
		n--;
	}
	return (SUCCESS);
}
