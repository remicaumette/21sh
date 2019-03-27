#include "parser.h"
#include <stdio.h>

t_redirection	*get_redir(t_token **ref)
{
	t_token			*curr;
	t_redirection	*tmp;

	curr = *ref;
	if (curr->type == TOKEN_GREATAND_4 || curr->type == TOKEN_GREATAND_3_TIP)
	{
		if ((tmp = redirection_create(curr->type, curr->content, NULL)) == NULL)
			return (NULL);
		*ref = curr->next;
		return (tmp);
	}
	else
	{
		if (curr->next == NULL)
			printf("%s: parse error near '%s'\n", "21sh", "\\n");
		else if (curr->next->type != TOKEN_WORD)
			printf("%s: parse error near '%s'\n", "21sh", curr->next->content);
		else
		{
			if (!(tmp = redirection_create(curr->type, curr->content, curr->next->content)))
				return (NULL);
			*ref = curr->next->next;
			return (tmp);
		}
		return (NULL);
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
