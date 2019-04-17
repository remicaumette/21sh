/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_processline.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:06:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 15:09:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		shell_cleanup(t_shell *shell)
{
	lexer_cleanup(shell->lexer);
	parser_cleanup(shell->parser);
	line_reset(shell->line);
}

static int	lexer_parser(t_shell *shell)
{
	if (lexer(shell) != SUCCESS)
		return (FAIL);
	if (parser_parse(shell) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int			shell_processline(t_shell *shell)
{
	int		out;

	out = 0;
	if (lexer_parser(shell) != SUCCESS)
		out = 1;
	if (shell->line->content == NULL)
		return (FAIL);
	if (!(history_insert(shell->history, shell->line->content)))
		out = 1;
	if (!out && shell->parser->root)
	{
		if (eval_all(shell) != SUCCESS)
			out = 1;
	}
	shell_cleanup(shell);
	if (shell->kill && shell->kill_str)
	{
		line_replace(shell->line, shell->kill_str);
		shell->kill_str = NULL;
		shell->kill = 0;
		return (shell_processline(shell));
	}
	return (out) ? FAIL : SUCCESS;
}
