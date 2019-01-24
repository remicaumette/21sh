#include "shell.h"

int		line_debug(t_line *line)
{
	t_winsize		tmp;

	dprintf(g_fd_debug, "\n");
	dprintf(g_fd_debug, "<CONTENT>%s</CONTENT>\n", line->content);
	dprintf(g_fd_debug, "<SIZE>%d</SIZE>\n", line->size);
	dprintf(g_fd_debug, "<CURSOR>%d</CURSOR>\n", line->cursor);
	dprintf(g_fd_debug, "<CUR_POS>\n");
	dprintf(g_fd_debug, "\t<WS_ROW>%d</WS_ROW>\n", line->cur_pos.ws_row);
	dprintf(g_fd_debug, "\t<WS_COL>%d</WS_COL>\n", line->cur_pos.ws_col);
	dprintf(g_fd_debug, "</CUR_POS>\n");
	dprintf(g_fd_debug, "<WINDOW>\n");
	dprintf(g_fd_debug, "\t<WS_ROW>%d</WS_ROW>\n", line->window.ws_row);
	dprintf(g_fd_debug, "\t<WS_COL>%d</WS_COL>\n", line->window.ws_col);
	dprintf(g_fd_debug, "</WINDOW>\n");

	if (window_getcurentpos(&tmp) != SUCCESS)
		dprintf(g_fd_debug, "Fail get curent pos\n");
	else
	{
		dprintf(g_fd_debug, "<REAL_POS>\n");
		dprintf(g_fd_debug, "\t<WS_ROW>%d</WS_ROW>\n", tmp.ws_row);
		dprintf(g_fd_debug, "\t<WS_COL>%d</WS_COL>\n", tmp.ws_col);
		dprintf(g_fd_debug, "</REAL_POS>\n");
	}
	return (SUCCESS);
}
