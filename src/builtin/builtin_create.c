/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 14:02:39 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:22:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_builtin		*builtin_create(char **argv, t_func_builtin func)
{
	t_builtin		*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_builtin))))
		return (NULL);
	if (!(tmp->argv = ft_strdup_2d((const char **)argv)))
		return (NULL);
	tmp->std[STDIN] = -1;
	tmp->std[STDOUT] = -1;
	tmp->std[STDERR] = -1;
	tmp->func = func;
	return (tmp);
}
