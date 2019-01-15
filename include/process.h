/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 12:55:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:38:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include <stdio.h>

typedef struct s_process	t_process;

struct						s_process
{
	char	*name;
	char	*cwd;
	char	**args;
	char	**env;
	pid_t	pid;
};

t_process					*process_create(char *name, char **args,
	char **env);
void						process_destroy(t_process *process);
int							process_start(t_process *process);
int							process_stop(t_process *process);
#endif
