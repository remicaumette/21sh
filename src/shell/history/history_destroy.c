/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_destroy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 14:53:07 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 16:08:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	history_destroy(t_history *history)
{
	t_histentry	*curr;
	int			i;

	if (history)
	{
		i = 0;
		curr = history->begin;
		while (curr && ++i <= history->size)
		{
			histentry_destroy(curr);
			curr = curr->next;
		}
		ft_memdel((void **)&history);
	}
}
