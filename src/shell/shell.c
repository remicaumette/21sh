/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:27:49 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 15:57:51 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell		*shell_create(char **environment)
{
	t_shell	*shell;

	if (!(shell = ft_memalloc(sizeof(t_shell))))
		return (NULL);
	shell->environment = NULL;
	shell->history = NULL;
	shell->line = NULL;
	shell->lexer = NULL;
	shell->parser = NULL;
	if (shell_envinit(shell, environment) ||
		!(shell->lexer = lexer_create()) ||
		!(shell->parser = parser_create(shell)))
		return (NULL);
	return (shell);
}

void		shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->environment)
			ft_strarr_del(shell->environment);
		if (shell->line)
			ft_strdel(&shell->line);
		if (shell->history)
			ft_strarr_del(shell->history);
		if (shell->lexer)
			lexer_destroy(shell->lexer);
		if (shell->parser)
			parser_destroy(shell->parser);
		ft_memdel((void **)&shell);
	}
}
