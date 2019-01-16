/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_return.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 15:28:52 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:29:07 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_return(t_shell *shell)
{
	write(1, "\n", 1);
	if (shell->line->content)
	{
		dprintf(1, "line->content: %s\n", shell->line->content);
		if (lexer_tokenize(shell->lexer, shell->line->content))
			return (!!shell->line->content);
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
		hist_push(shell->line->content);
		line_reset(shell->line);
	}
	shell_prompt(shell);
	return (SUCCESS);
}
