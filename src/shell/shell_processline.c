/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_processline.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:06:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:52:04 by rcaumett    ###    #+. /#+    ###.fr     */
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

// static void	debug_parser(t_node *node)
// {
// 	for (int i = 0; i < 21; i++) {
// 		if (g_tokens[i].type == node->type) {
// 			printf("node->type: %s\n", g_tokens[i].format);
// 			break;
// 		}
// 	}
// 	if (node->command) {
// 		printf("node->command->name: %s\n", node->command->name);
// 		for (int i = 0; i < ft_strarr_len(node->command->arguments); i++) {
// 			printf("node->command->arguments[%d]: %s\n", i, node->command->arguments[i]);
// 		}
// 	}
// 	printf("======\n");
// 	if (node->next)
// 		debug_parser(node->next);
// }

int			shell_processline(t_shell *shell)
{
	int		out;

	out = 0;
	if (lexer_parser(shell) != SUCCESS)
		out = 1;
	if (!(history_insert(shell->history, shell->line->content)))
		out = 1;
	if (!out && shell->parser->root)
	{
		// debug_parser(shell->parser->root);
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
