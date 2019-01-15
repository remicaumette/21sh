/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 12:51:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:35:18 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_process	*process_create(char *name, char **args, char **env)
{
	t_process	*process;

	if (!(process = ft_memalloc(sizeof(t_process))) ||
		!(process->name = ft_strdup(name)) ||
		!(process->args = ft_strarr_clone(args)) ||
		!(process->env = ft_strarr_clone(env)))
		return (NULL);
	return (process);
}
