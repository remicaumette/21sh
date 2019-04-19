/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_destroy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 15:28:28 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 16:43:08 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		builtin_destroy(t_builtin **as)
{
	t_builtin	*builtin;

	if (as)
		builtin = *as;
	else
		return ;
	if (builtin)
	{
		ft_strdel_2d(&builtin->argv);
		if (builtin->STDIN != -1)
			close(builtin->STDIN);
		if (builtin->STDOUT != -1)
			close(builtin->STDOUT);
		if (builtin->STDERR != -1)
			close(builtin->STDERR);
	}
	free(*as);
	*as = NULL;
}
