/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_destroy.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 13:08:05 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:08:06 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

void	parser_destroy(t_parser **as)
{
	t_parser	*parser;

	parser = *as;
	if (parser)
	{
		parser_cleanup(parser);
		ft_memdel((void **)as);
		*as = NULL;
	}
}
