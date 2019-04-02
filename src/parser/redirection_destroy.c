/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_destroy.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:13:54 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:13:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parser.h"

void	redirection_destroy(t_redirection **as)
{
	t_redirection		*redirection;

	redirection = *as;
	if (redirection)
	{
		if (redirection->file)
			ft_strdel(&redirection->file);
		if (redirection->symbols)
			ft_strdel(&redirection->symbols);
		ft_memdel((void **)as);
		*as = NULL;
	}
}
