/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hist_get.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 15:21:22 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 14:11:24 by rcaumett    ###    #+. /#+    ###.fr     */
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
	return (SUCCESS);
}
