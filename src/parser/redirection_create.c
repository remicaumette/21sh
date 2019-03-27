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

t_redirection	*redirection_create(t_tokentype type, char *file, char *symbols)
{
	t_redirection	*redirection;

	if (!(redirection = ft_memalloc(sizeof(t_redirection))))
		return (NULL);
	if (!(redirection->file = ft_strdup(file)))
		return (NULL);
	if (!(redirection->symbols = ft_strdup(symbols)))
		return (NULL);
	redirection->type = type;
	redirection->next = NULL;
	return (redirection);
}
