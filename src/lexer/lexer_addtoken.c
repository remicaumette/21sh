/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer_addtoken.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 13:07:58 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:08:00 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lexer.h"

t_token	*lexer_addtoken(t_lexer *lexer, t_tokentype type,
	char *content)
{
	t_token	*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
		return (NULL);
	token->type = type;
	token->content = NULL;
	token->next = NULL;
	if (content && !(token->content = ft_strdup(content)))
		return (NULL);
	if (!lexer->begin)
		lexer->begin = token;
	if (lexer->end)
		lexer->end->next = token;
	lexer->end = token;
	lexer->count++;
	return (token);
}
