/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:13:20 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lexer.h"

t_tokeninfo	g_tokens[] = {
	{"2>&1", TOKEN_GREATAND_4_TIP, 4},
	{"1>&2", TOKEN_GREATAND_4_TIP, 4},
	{"2>&-", TOKEN_GREATAND_4, 4},
	{"1>&-", TOKEN_GREATAND_4, 4},
	{"0>&-", TOKEN_GREATAND_4, 4},
	{">&-", TOKEN_GREATAND_3_TIP, 3},
	{"2>&", TOKEN_GREATAND_3, 3},
	{"2>>", TOKEN_DGREAT_3, 3},
	{"1>>", TOKEN_DGREAT_3, 3},
	{"2>", TOKEN_GREAT_2, 2},
	{"1>", TOKEN_GREAT_2, 2},
	{"<<", TOKEN_DLESS, 2},
	{">>", TOKEN_DGREAT, 2},
	{"<&", TOKEN_LESSAND, 2},
	{">&", TOKEN_GREATAND, 2},
	{"|", TOKEN_PIPE, 1},
	{">", TOKEN_GREAT, 1},
	{"<", TOKEN_LESS, 1},
	{";", TOKEN_NEWLINE, 1},
	{"\n", TOKEN_NEWLINE, 1},
	{NULL, TOKEN_WORD, 0}
};

t_tokentype	lexer_gettype(char *str)
{
	int	i;

	i = -1;
	while (g_tokens[++i].len)
		if (ft_strnequ(str, g_tokens[i].format, g_tokens[i].len))
			return (g_tokens[i].type);
	return (TOKEN_WORD);
}

char		lexer_getmissingtoken(t_lexer *lexer)
{
	t_token	*curr;
	t_token	*last;

	if (lexer->quote != -1)
		return (lexer->quote);
	curr = lexer->begin;
	last = NULL;
	while (curr)
	{
		if (curr->type != TOKEN_NEWLINE)
			last = curr;
		curr = curr->next;
	}
	if (last && last->type == TOKEN_PIPE)
		return ('|');
	return (-1);
}
