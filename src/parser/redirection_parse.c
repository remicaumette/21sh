/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_parse.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:32:19 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:32:36 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

int			redirection_parse(t_redirection **redirection, t_parser *parser)
{
	t_token			*curr;
	t_redirection	*tmp;

	curr = parser->curr;
	if (!(curr->next) || curr->next->type != TOKEN_WORD)
		return (FAIL);
	if (!(tmp = redirection_create(curr->type, curr->next->content)))
		return (FAIL);
	*redirection = tmp;
	curr = curr->next->next;
	while (curr && parser_istoken_redirection(curr->type))
	{
		if (!(curr->next) || curr->next->type != TOKEN_WORD)
			return (FAIL);
		if (!(tmp->next = redirection_create(curr->type, curr->next->content)))
			return (FAIL);
		curr = curr->next->next;
	}
	parser->curr = curr;
	return (SUCCESS);
}
