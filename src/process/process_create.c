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

	if (!(process = ft_memalloc(sizeof(t_process))) ||
		!(process->file = ft_strdup(file)) ||
		pipe(process->stdin) == -1 ||
		pipe(process->stdout) == -1 ||
		pipe(process->stderr) == -1)
		return (NULL);
	process->args = ft_strarr_clone(args);
	process->env = ft_strarr_clone(env);
	process->error = 0;
	process->status = -1;
	process->pid = -1;
	ft_bzero((void *)process->isset, sizeof(int [3]));
	return (process);
}
