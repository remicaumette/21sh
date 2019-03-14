/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_create.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:13:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:13:12 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

t_parser	*parser_create(void)
{
	t_parser	*parser;

	if (!(parser = ft_memalloc(sizeof(t_parser))))
		return (NULL);
	parser->root = NULL;
	parser->curr = NULL;
	return (parser);
}
