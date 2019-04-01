/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_expand.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 14:50:43 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 17:13:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char		*expand_var(t_shell *shell, char *token, char **str, int *i)
{
	char	*var;
	char	*val;

	var = NULL;
	while (ft_isalnum(token[*i + 1]) || token[*i + 1] == '_')
	{
		if (!(ft_strjoinc(&var, token[*i + 1])))
			return (NULL);
		(*i)++;
	}
	val = shell_getenv(shell, var);
	ft_strdel(&var);
	if (!val)
		return (*str);
	if (!(var = ft_strjoin(*str, val)))
		return (NULL);
	ft_strdel(str);
	return (*str = var);
}

char		*expand_home(t_shell *shell, char **str)
{
	char	*home;
	char	*tmp;
	
	home = shell_getenv(shell, "HOME");
	if (!(tmp = ft_strjoin(*str, home)))
		return (NULL);
	ft_strdel(str);
	return (*str = tmp);
}

static char	*expand_token(t_shell *shell, char *token)
{
	char	*str;
	char	quote;
	int		i;

	str = NULL;
	quote = -1;
	i = -1;
	while (token[++i])
	{
		if ((token[i] == '"' || token[i] == '\'') && (quote == -1 || token[i] == quote))
			quote = quote == -1 ? token[i] : -1;
		else if (token[i] == '$' && quote != '\'')
		{
			if (!expand_var(shell, token, &str, &i))
				return (NULL);
		}
		else if (token[i] == '~' && quote == -1)
		{
			if (!expand_home(shell, &str))
				return (NULL);
		}
		else
		{
			if (!ft_strjoinc(&str, token[i]))
				return (NULL);
		}
	}
	return (str);
}

int			parser_expand(t_shell *shell)
{
	t_token	*token;
	char	*prev;
	
	token = shell->lexer->begin;
	while (token)
	{
		if (token->type == TOKEN_WORD)
		{
			prev = token->content;
			if (!(token->content = expand_token(shell, token->content)))
				return (1);
			ft_strdel(&prev);
		}
		token = token->next;
	}
	return (0);
}
