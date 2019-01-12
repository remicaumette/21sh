#include "line_edit.h"
#include "debug.h"


static void		print_pos(int fd, t_cursor *cursor)
{
	t_point		var;

	ft_winpos(&var);
	dprintf(fd, "\n\tPos\n");
	dprintf(fd, "winsize : x=%d, y=%d\n", cursor->winsize->x, cursor->winsize->y);
	dprintf(fd, "current : x=%d, y=%d\n", cursor->pos.x, cursor->pos.y);
	dprintf(fd, "true    : x=%d, y=%d\n", var.x, var.y);
}

static void		print_lchar(int fd, t_cursor *cursor)
{
	char			*tmp;

	dprintf(fd, "\n\tPointeur\n");
	if (cursor->current)
		dprintf(fd, "current=%c\n", cursor->current->c);
	else
		dprintf(fd, "current=NULL\n");
	dprintf(fd, "first=");
	if (cursor->first)
		dprintf(fd, "%c\n", cursor->first->c);
	else
		dprintf(fd, "NULL\n");
	dprintf(fd, "last=");
	if (cursor->last)
		dprintf(fd, "%c\n", cursor->last->c);
	else
		dprintf(fd, "NULL\n");
	dprintf(fd, "line=");
	tmp = ft_lCharto_str(cursor->first);
	if (tmp == NULL || *tmp == '\0')
		dprintf(fd, "NULL\n");
	else
	{
		dprintf(fd, "%s\n", tmp);
		ft_strdel(&tmp);
	}
}

void	logdebug(t_cursor *cursor, char c)
{

	DEBUG_FD("./line_edit.log")

	dprintf(fd, "\n\t\t Char=%c\n", c);
	print_lchar(fd, cursor);
	dprintf(fd, "dist_first=%d\ndist_last=%d\n", cursor->dist_first, cursor->dist_last);
	print_pos(fd, cursor);
}
