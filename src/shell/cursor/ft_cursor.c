#include "line_edit.h"

static inline	void	reset(t_cursor *cursor)
{
	ft_lChardel_all(&cursor->first);
	cursor->dist_first = -1;
	cursor->dist_last = -1;
	cursor->current = NULL;
	cursor->first = NULL;
	cursor->last = NULL;
}

t_cursor				*ft_cursor(t_flag action)
{
	static t_cursor		*cursor = NULL;

	if (cursor == NULL)
	{
		if ((cursor = malloc(sizeof(cursor))) == NULL)
			return (NULL);
		ft_cursorinit(cursor);
	}
	if (action & CUR_RESET)
		reset(cursor);
	if (action & CUR_SET_CURRENT)
		ft_winpos(&cursor->pos);
	if (action & CUR_SET_WINSIZE)
		cursor->winsize = ft_winsize(SET);
	if (action & CUR_FREE)
		ft_cursordel_all(&cursor);
	return (cursor);
}
