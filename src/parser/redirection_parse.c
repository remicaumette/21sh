/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_parse.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:35:13 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 12:23:07 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

static int		check_error(t_token *curr)
{
	if (curr->next == NULL)
	{
		ft_putstr_fd("21sh: parse error near '\\n'\n", STDERR_FILENO);
		return (1);
	}
	if (curr->next->type != TOKEN_WORD)
	{
		ft_putstr_fd("21sh: parse error near ", STDERR_FILENO);
		ft_putendl_fd(curr->next->content, STDERR_FILENO);
		return (1);
	}
	return (0);
}

t_redirection	*get_redir(t_token **ref)
{
	t_token			*curr;
	t_redirection	*tmp;

	curr = *ref;
	if (token_isfile_redir(curr->type) || curr->type == TOKEN_DLESS)
	{
		if (check_error(curr))
			return (NULL);
		else
		{
			if (!(tmp = redirection_create(curr->type, curr->content,
							curr->next->content)))
				return (NULL);
			*ref = curr->next->next;
			return (tmp);
		}
	}
	else
	{
		if ((tmp = redirection_create(curr->type, curr->content, NULL)) == NULL)
			return (NULL);
		*ref = curr->next;
		return (tmp);
	}
}

int				redirection_parse(t_redirection **redirection, t_parser *parse)
{
	t_redirection	*tmp;

	if ((*redirection = get_redir(&parse->curr)) == NULL)
		return (FAIL);
	tmp = *redirection;
	while (parse->curr && token_isredirection(parse->curr->type))
	{
		if ((tmp->next = get_redir(&parse->curr)) == NULL)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
