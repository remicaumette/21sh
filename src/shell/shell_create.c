/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_create.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:18:37 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:42:32 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell	*shell_create(char **environment)
{
	t_shell	*shell;

	if (!(shell = ft_memalloc(sizeof(t_shell))))
		return (NULL);
	shell->kill = 0;
	shell->environment = NULL;
	shell->history = NULL;
	shell->line = NULL;
	shell->lexer = NULL;
	shell->parser = NULL;
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
