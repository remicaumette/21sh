/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_all.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:17:51 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 10:21:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		eval_all(t_shell *shell)
{
	t_node		*curr;

	curr = shell->parser->root;
	if (curr->type)
	{
		printf("syntax error: unexpected token\n");
		return (SUCCESS);
	}
	while (curr && !shell->kill)
	{
		eval_line(curr, shell);
		while (curr && curr->type != TOKEN_NEWLINE)
			curr = curr->next;
		if (curr)
			curr = curr->next;
	}
	return (SUCCESS);
}
