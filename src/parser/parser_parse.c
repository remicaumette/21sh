/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_parse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:12:30 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 15:18:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		parser_parse(t_shell *shell)
{
	t_command	*cmd;
	t_token		*curr;
	t_node		*node;

	cmd = NULL;
	shell->parser->curr = shell->lexer->begin;
	if (parser_expand(shell))
		return (1);
	while (shell->parser->curr)
	{
		cmd = NULL;
		curr = shell->parser->curr;
		cmd = NULL;
		if (curr->type == TOKEN_WORD && !(cmd = command_parse(shell->parser)))
			return (1);
		if (!(node = node_create(curr->type, cmd)))
			return (1);
		node_insert(&shell->parser->root, node);
		shell->parser->curr = curr->type == TOKEN_WORD ?
			shell->parser->curr : curr->next;
	}
	return (0);
}
