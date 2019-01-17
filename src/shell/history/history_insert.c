/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_insert.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 15:29:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 15:54:12 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_histentry	*history_insert(t_history *history, char *content)
{
	t_histentry	*entry;

	if (!(entry = histentry_create(content)))
		return (NULL);
	entry->prev = history->end;
	entry->next = history->begin;
	if (!(history->begin))
		history->begin = entry;
	history->end = entry;
	history->size++;
	return (entry);
}
