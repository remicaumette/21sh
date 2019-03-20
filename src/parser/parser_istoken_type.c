/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_istoken_type.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:31:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:31:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

int		parser_istoken_redirection(t_tokentype type)
{
	if (type == TOKEN_GREAT || type == TOKEN_DGREAT || type == TOKEN_GREATAND
		|| type == TOKEN_LESS || type == TOKEN_DLESS || type == TOKEN_LESSAND
		|| type == TOKEN_LESSGREAT)
		return (1);
	return (0);
}
