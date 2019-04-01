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

void	node_destroy(t_node *node)
{
	t_node	*curr;
	t_node	*next;

	next = node;
	while (next)
	{
		curr = next;
		next = curr->next;
		printf("node: %p\n", curr);
		if (curr->command)
			command_destroy(curr->command);
		ft_memdel((void **)&curr);
	}
}
