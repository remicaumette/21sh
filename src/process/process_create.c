/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_create.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 12:51:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:54:07 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

t_process	*process_create(char *file, char **args, char **env)
{
	t_process	*process;

	if (!(process = ft_memalloc(sizeof(t_process))))
		return (NULL);
	if (!(process->file = ft_strdup(file)))
		return (NULL);
	process->args = ft_strarr_clone(args);
	process->env = ft_strarr_clone(env);
	process->error = 0;
	process->status = -1;
	process->pid = -1;
	process->std[STDIN] = -1;
	process->std[STDOUT] = -1;
	process->std[STDERR] = -1;
	process->isset[STDIN] = 0;
	process->isset[STDOUT] = 0;
	process->isset[STDERR] = 0;
	return (process);
}
