/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_destroy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 15:28:28 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:52:22 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		builtin_destroy(t_builtin **as)
{
	t_builtin	*builtin;

	builtin = *as;
	if (builtin)
	{
		ft_strdel_2d(&builtin->argv);
		if (builtin->std[STDIN] != -1)
			close(builtin->std[STDIN]);
		if (builtin->std[STDOUT] != -1)
			close(builtin->std[STDOUT]);
		if (builtin->std[STDERR] != -1)
			close(builtin->std[STDERR]);
	}
	free(*as);
	*as = NULL;
}
