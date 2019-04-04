/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:34:37 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:34:38 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	get_quote(t_shell *shell)
{
	t_ret	ret;

	line_inser(shell->line, '\n');
	if (shell->missing_token == '"')
		ft_putstr("dquote> ");
	else if (shell->missing_token == '\\')
		ft_putstr("quote> ");
	while ((ret = shell_getline(shell)) == RET_STOP)
		;
	if (ret == RET_SUCCESS)
		return (lexer(shell));
	else
		return (FAIL);
}

int			lexer(t_shell *shell)
{
	lexer_cleanup(shell->lexer);
	if (lexer_tokenize(shell->lexer, shell->line->content))
		return (FAIL);
	if ((shell->missing_token = lexer_getmissingtoken(shell->lexer)) == -1)
		return (SUCCESS);
	else
		return (get_quote(shell));
}
