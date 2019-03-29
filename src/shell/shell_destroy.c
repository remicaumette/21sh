/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_destroy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:18:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:43:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->environment)
			ft_strarr_del(shell->environment);
		if (shell->history)
			history_destroy(shell->history);
		if (shell->lexer)
			lexer_destroy(shell->lexer);
		if (shell->parser)
			parser_destroy(shell->parser);
		if (shell->line)
			line_destroy(&shell->line);
		if (shell->term)
			term_destroy(&shell->term);
		if (shell->eval)
			eval_destroy(&shell->eval);
		ft_memdel((void **)&shell);
	}
}
