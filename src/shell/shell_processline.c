/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_processline.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:06:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 15:01:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	debug(t_shell *shell)
{
	printf("=== TOKEN\n");
	if (shell->lexer->begin)
		print_token(shell->lexer->begin);
	printf("=== PARSER\n");
	if (shell->parser->root)
		print_node(shell->parser->root);
}

static void	clean_thing(t_shell *shell)
{
	lexer_cleanup(shell->lexer);
	parser_cleanup(shell->parser);
	line_reset(shell->line);
}

static int	lexer_parser(t_shell *shell)
{
	if (lexer_tokenize(shell->lexer, shell->line->content))
		return (FAIL);
	shell->missing_token = lexer_getmissingtoken(shell->lexer);
	if (shell->lexer->begin && shell->missing_token == -1)
	{
		if (parser_parse(shell) != SUCCESS)
			return (FAIL);
	}
	debug(shell);
	return (SUCCESS);
}

int			shell_processline(t_shell *shell)
{
	int		out;

	out = 0;
	if (lexer_parser(shell) != SUCCESS)
		out = 1;
	if (!out && shell->parser->root)
	{
		if (eval_all(shell) != SUCCESS)
			out = 1;
	}
	if (!(history_insert(shell->history, shell->line->content)))
		out = 1;
	clean_thing(shell);
	return (out) ? FAIL : SUCCESS;
}
