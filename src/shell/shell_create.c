/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_create.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:18:37 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:33:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell	*shell_create(char **environment)
{
	t_shell	*shell;

	if (!(shell = ft_memalloc(sizeof(t_shell))))
		return (NULL);
	shell->environment = NULL;
	shell->history = NULL;
	shell->line = NULL;
	shell->lexer = NULL;
	shell->parser = NULL;
	shell->kill = 0;
	shell->kill_str = NULL;
	if (shell_envinit(shell, environment) ||
		!(shell->line = line_create()) ||
		!(shell->term = term_create(shell)) ||
		!(shell->history = history_create()) ||
		!(shell->lexer = lexer_create()) ||
		!(shell->parser = parser_create()) ||
		!(shell->eval = eval_create(NULL, NULL)))
		return (NULL);
	return (shell);
}
