/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansion.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 18:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 12:54:41 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*parser_expandword(t_parser *parser, t_token *token)
{
	char	*word;
	char	*tmp;

	(void)parser;
	word = NULL;
	tmp = token->content - 1;
	while (*++tmp)
	{
		(void)ft_strjoinc;
	}
	return (tmp);
}
