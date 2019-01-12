#include "line_edit.h"

void		ft_cursordel_all(t_cursor **cursor)
{
	t_cursor		*tmp;
	t_lChar			*begin_lst;

	tmp = *cursor;
	begin_lst = ft_lCharfirst(tmp->current);
	ft_lChardel_all(&begin_lst);
	tmp->current = NULL;
	free(tmp);
	*cursor = NULL;
}
