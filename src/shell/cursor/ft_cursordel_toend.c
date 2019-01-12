#include "line_edit.h"

void				ft_cursordel_toend(t_cursor *cursor)
{
	if (cursor->dist_last == -1)
		return ;
	if (cursor->dist_first == 0)
	{
		ft_cursor(CUR_RESET);
		return ;
	}
	else
	{
		cursor->last = cursor->current->prev;
		cursor->last->next = NULL;
		ft_lChardel_all(&(cursor->current));
		cursor->dist_last = -1;
	}
}
