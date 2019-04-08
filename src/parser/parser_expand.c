/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_expand.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 14:50:43 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 15:13:00 by rcaumett    ###    #+. /#+    ###.fr     */
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

static int	process_token_expansion(t_valise *v)
{
	if ((v->token[v->i] == '"' || v->token[v->i] == '\'') &&
		(v->quote == -1 || v->token[v->i] == v->quote))
		v->quote = v->quote == -1 ? v->token[v->i] : -1;
	else if (v->token[v->i] == '$' && v->quote != '\'')
	{
		if (!expand_var(v->shell, v->token, &v->str, &v->i))
			return (1);
	}
	else if (v->token[v->i] == '~' && v->quote == -1)
	{
		if (!expand_home(v->shell, &v->str))
			return (1);
	}
	else
	{
		if (!ft_strjoinc(&v->str, v->token[v->i]))
			return (1);
	}
	return (0);
}

static char	*expand_token(t_shell *shell, char *token)
{
	t_valise	v;

	v = (t_valise) {
		.shell = shell,
		.token = token,
		.str = NULL,
		.quote = -1,
		.i = -1,
	};
	while (v.token[++v.i])
		if (process_token_expansion(&v))
			return (NULL);
	return (v.str);
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
