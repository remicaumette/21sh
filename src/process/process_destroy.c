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

#include "process.h"

int		process_destroy(t_process **as)
{
	t_process	*process;

	process = *as;
	if (process)
	{
		if (process->file)
			ft_strdel(&process->file);
		if (process->cwd)
			ft_strdel(&process->cwd);
		if (process->args)
			ft_strarr_del(process->args);
		if (process->env)
			ft_strarr_del(process->env);
		if (process->STDIN > -1)
			close(process->STDIN);
		if (process->STDOUT > -1)
			close(process->STDOUT);
		if (process->STDERR > -1)
			close(process->STDERR);
		ft_memdel((void **)as);
	}
	return (FAIL);
}
