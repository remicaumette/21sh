#include "history.h"

/*
**	2 fonction for get history
**	up return prev node in stack 
**	donw return next node in stack
**	this stack is circular
**
**	Parametres
**	----------
**	line : &char *
**		address to stock the the line
**
**	Returns
**	-------
**	int :
**		SUCCESS => *line OK
**		FAIL	=> *line = NULL
**					maby malloc fail or line = NULL or no history
*/
int			ft_histget_up(char **line)
{
	t_stackhist		*history;

	history = ft_hist();
	if (line == NULL || history->size == 0)
		return (FAIL);
	if (history->tmp == NULL)
		history->tmp = history->last;
	*line = ft_strdup((char *)history->tmp->data);
	history->tmp = history->tmp->prev;
	ft_histdebug();
	return (SUCCESS);
}

int			ft_histget_down(char **line)
{
	t_stackhist		*history;

	history = ft_hist();
	if (line == NULL || history->size == 0)
		return (FAIL);
	if (history->tmp == NULL)
		history->tmp = history->first;
	*line = ft_strdup((char *)history->tmp->data);
	history->tmp = history->tmp->next;
	ft_histdebug();
	return (SUCCESS);
}
