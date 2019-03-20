/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_processline.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:06:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:41:27 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*static void	debug(t_shell *shell)
{
	printf("=== TOKEN\n");
	print_token(shell->lexer->begin);
	printf("=== PARSER\n");
	print_node(shell->parser->root);
}*/

int			shell_processline(t_shell *shell)
{
	int		out;

	out = 1;
	if (lexer_tokenize(shell->lexer, shell->line->content))
		out = 0;
	shell->missing_token = lexer_getmissingtoken(shell->lexer);
	if (out && shell->lexer->begin)
	{
		if (out && shell->missing_token == -1)
		{
			if (parser_parse(shell->parser, shell->lexer) != SUCCESS)
				out = 0;
			if (out && shell->parser->root)
			{
				if (eval_all(shell) != SUCCESS)
					out = 0;
			}
		}
		lexer_cleanup(shell->lexer);
		parser_cleanup(shell->parser);
	}
	if (out && !(history_insert(shell->history, shell->line->content)))
		out = 0;
	line_reset(shell->line);
	return (out) ? SUCCESS : FAIL;
}
