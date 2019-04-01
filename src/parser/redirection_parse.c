#include "parser.h"
#include <stdio.h>

t_redirection	*get_redir(t_token **ref)
{
	t_token			*curr;
	t_redirection	*tmp;

	curr = *ref;
	if (token_isfile_redir(curr->type) || curr->type == TOKEN_DLESS)
	{
		if (curr->next == NULL)
			ft_putstr_fd("21sh: parse error near '\\n'\n", STDERR_FILENO);
		else if (curr->next->type != TOKEN_WORD)
		{
			ft_putstr_fd("21sh: parse error near ",STDERR_FILENO);
			ft_putendl_fd(curr->next->content, STDERR_FILENO);
		}
		else
		{
			if (!(tmp = redirection_create(curr->type, curr->content, curr->next->content)))
				return (NULL);
			*ref = curr->next->next;
			return (tmp);
		}
		return (NULL);
	}
	else
	{
		if ((tmp = redirection_create(curr->type, curr->content, NULL)) == NULL)
			return (NULL);
		*ref = curr->next;
		return (tmp);
	}
}

int		redirection_parse(t_redirection **redirection, t_parser *parse)
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
