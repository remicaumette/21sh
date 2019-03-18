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

/*
static void	debug(t_shell *shell)
{
	printf("=== TOKEN\n");
	print_token(shell->lexer->begin);
	printf("=== PARSER\n");
	print_node(shell->parser->root);
}
*/

int			shell_processline(t_shell *shell)
{
	if (lexer_tokenize(shell->lexer, shell->line->content))
		return (!!shell->line->content);
	shell->missing_token = lexer_getmissingtoken(shell->lexer);
	if (shell->lexer->begin)
	{
		if (shell->missing_token == -1)
		{
			if (parser_parse(shell->parser, shell->lexer) != SUCCESS)
				return (FAIL);
			if (shell->parser->root)
			{
				if (eval_all(shell) != SUCCESS)
					return (FAIL);
			}
			term_row_stop(shell);
			term_row_start(shell);
		}
		lexer_cleanup(shell->lexer);
		parser_cleanup(shell->parser);
	}
	if (!(history_insert(shell->history, shell->line->content)))
		return (FAIL);
	line_reset(shell->line);
	return (SUCCESS);
}
