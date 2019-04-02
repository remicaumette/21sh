/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:11:30 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:11:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	node_destroy(t_node **as)
{
	t_node	*curr;
	t_node	*next;

	next = *as;
	while (next)
	{
		curr = next;
		next = curr->next;
		if (curr->command)
			command_destroy(&curr->command);
		ft_memdel((void **)&curr);
	}
	*as = NULL;
}
