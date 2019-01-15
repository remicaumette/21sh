/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_destroy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:01:57 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:04:04 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	process_destroy(t_process *process)
{
	if (process)
	{
		if (process->name)
			ft_strdel(&process->name);
		if (process->cwd)
			ft_strdel(&process->cwd);
		if (process->args)
			ft_strarr_del(process->args);
		if (process->env)
			ft_strarr_del(process->env);
		ft_memdel((void **)&process);
	}
}
