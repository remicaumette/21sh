/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_all.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:17:51 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 18:17:52 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "eval.h"

int		eval_all(t_shell *shell)
{
	t_node		*curr;

	curr = shell->parser->root;
	while (curr)
	{
		if (eval_line(curr, shell) != SUCCESS)
			return (FAIL);
		while (curr && curr->type != TOKEN_NEWLINE)
			curr = curr->next;
		if (curr)
			curr = curr->next;
	}
	return (SUCCESS);
}
