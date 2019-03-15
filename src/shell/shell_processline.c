/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_processline.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:06:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:10:28 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	debug(t_shell *shell)
{
	printf("=== TOKEN\n");
	print_token(shell->lexer->begin);
	printf("=== PARSER\n");
	print_node(shell->parser->root);
}

int			shell_processline(t_shell *shell)
{
	if (parser_parse(shell->parser, shell->lexer) != SUCCESS)
		return (FAIL);
	debug(shell);
	if (shell->parser->root)
	{
		if (eval_all(shell) != SUCCESS)
			return (FAIL);
	}
	return (SUCCESS);
}
