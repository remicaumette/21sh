/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_insert.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 15:29:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 14:27:39 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_histentry	*history_insert(t_history *history, char *content)
{
	t_histentry	*entry;

	ft_strdel(&history->tmp);
	if (!(entry = histentry_create(content)))
		return (NULL);
	if (history->begin)
		history->begin->prev = entry;
	entry->next = history->begin;
	entry->prev = NULL;
	history->size++;
	history->begin = entry;
	if (!history->end)
		history->end = entry;
	history->curr = NULL;
	return (entry);
}
