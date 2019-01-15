/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_return.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 14:50:00 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 10:14:27 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		tmp_func(t_shell *shell)
{
		if ((shell->line = ft_lCharto_str(shell->cursor->first)) == NULL)
			return (FAIL);
		return (SUCCESS);
}

int				action_return(t_shell *shell)
{
	write(1, "\n", 1);
	if (tmp_func(shell) != SUCCESS)
		return (FAIL);
	if (!shell->line || lexer_tokenize(shell->lexer, shell->line))
		return (!!shell->line);
	shell->missing_token = lexer_getmissingtoken(shell->lexer);
	if (shell->lexer->begin)
	{
		if (shell->missing_token == -1)
		{
			printf("=== TOKEN\n");
			print_token(shell->lexer->begin);
			printf("=== PARSER\n");
			printf("parser_parse = %d\n", parser_parse(shell->parser));
			print_node(shell->parser->root);
		}
		lexer_cleanup(shell->lexer);
		parser_cleanup(shell->parser);
	}
	ft_strdel(&shell->line);
	shell_prompt(shell);
	ft_cursor(CUR_RESET | CUR_SET_ALL);
	return (SUCCESS);
}
/*
int		action_return(t_shell *shell)
{
	(void)shell;
	ft_putstr("\n");
	ft_cursor(CUR_RESET | CUR_SET_ALL);
	shell_prompt(shell);
	return (SUCCESS);
}*/
