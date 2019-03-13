#include "shell.h"

void		term_destroy(t_term **term)
{
	t_term		*tmp;

	tmp = *term;
	if (tmp != NULL)
	{
		if (tmp->save)
		{
			free(tmp->save);
			tmp->save = NULL;
		}
		if (tmp->my)
		{
			free(tmp->my);
			tmp->my = NULL;
		}
		free(tmp);
	}
	*term = NULL;
}
