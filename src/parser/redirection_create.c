/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_create.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:13:34 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:13:35 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

t_redirection	*redirection_create(t_tokentype type, char *file)
{
	t_redirection	*redirection;

	if (!(redirection = ft_memalloc(sizeof(t_redirection))) ||
		!(redirection->file = ft_strdup(file)))
		return (NULL);
	redirection->type = type;
	redirection->next = NULL;
	if (type == TOKEN_LESS || type == TOKEN_DLESS || type == TOKEN_LESSAND)
		redirection->in = 1;
	else
		redirection->in = 0;
	if (type == TOKEN_GREAT || type == TOKEN_DGREAT || type == TOKEN_GREATAND)
		redirection->out = 1;
	else
		redirection->out = 0;
	return (redirection);
}
