/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_histget.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 15:21:22 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 15:27:17 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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
int			hist_getup(char **line)
{
	t_stackhist		*history;

	history = hist();
	if (line == NULL || history->size == 0)
		return (FAIL);
	if (history->tmp == NULL)
		history->tmp = history->last;
	*line = ft_strdup((char *)history->tmp->data);
	history->tmp = history->tmp->prev;
	ft_histdebug();
	return (SUCCESS);
}

int			hist_getdown(char **line)
{
	t_stackhist		*history;

	history = hist();
	if (line == NULL || history->size == 0)
		return (FAIL);
	if (history->tmp == NULL)
		history->tmp = history->first;
	*line = ft_strdup((char *)history->tmp->data);
	history->tmp = history->tmp->next;
	ft_histdebug();
	return (SUCCESS);
}
