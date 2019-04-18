/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:34:37 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 14:07:29 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	kill_save(char *save_line, t_shell *shell)
{
	if (save_line)
		ft_strdel(&save_line);
	shell->kill_str = ft_strdup(shell->line->content);
	return (FAIL);
}

static int	get_quote(t_shell *shell)
{
	char	*new_line;
	char	*save_line;
	t_ret	ret;

	if ((save_line = ft_strdup(shell->line->content)) == NULL)
		return (FAIL);
	line_reset(shell->line);
	if (shell->missing_token == '"' || shell->missing_token == '\'')
		ft_putstr(shell->missing_token == '"' ? "dquote" : "quote");
	ft_putstr("> ");
	while ((ret = shell_getline(shell)) == RET_STOP && !shell->kill)
		;
	if (shell->kill)
		return (kill_save(save_line, shell));
	if (ret == RET_SUCCESS)
	{
		if ((new_line = ft_strjoinc(&save_line, '\n')) == NULL)
			return (FAIL);
		if ((new_line = ft_strjoinfree(&save_line,
						&shell->line->content, 1)) == NULL)
			return (FAIL);
		line_replace(shell->line, new_line);
		return (lexer(shell));
	}
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
