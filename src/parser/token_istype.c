/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token_istype.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 15:27:57 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:28:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

int		token_isredirection(t_tokentype type)
{
	if (type == TOKEN_GREAT || type == TOKEN_DGREAT || type == TOKEN_GREATAND
		|| type == TOKEN_LESS || type == TOKEN_DLESS || type == TOKEN_LESSAND
		|| type == TOKEN_LESSGREAT || type ==TOKEN_GREATAND_3 
		|| type == TOKEN_GREATAND_4)
		return (1);
	return (0);
}

int		token_isfile_redir(t_tokentype type)
{
	if (type == TOKEN_GREAT || type == TOKEN_DGREAT || 
			type == TOKEN_GREAT_2 || type == TOKEN_GREATAND_3)
		return (1);
	return (0);
}
