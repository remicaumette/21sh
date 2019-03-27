/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 12:55:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:50:34 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "debug.h"

# ifdef __linux__
#  include <sys/types.h>
#  include <sys/wait.h>
# endif

# ifndef SUCCESS
#  define SUCCESS			0
#  define FAIL				1
# endif

# define BUFF_READ_SIZE		1024

typedef struct s_process	t_process;

struct						s_process
{
	char	*file;
	char	*cwd;
	char	**args;
	char	**env;
	pid_t	pid;
	int		status;
	int		error;
	int		isset[3];
	int		stdin[2];
	int		stdout[2];
	int		stderr[2];
};

t_process					*process_create(char *file, char **args,
	char **env);
void						process_destroy(t_process **as);
int							process_run(t_process *process);

int							process_start(t_process *process);
int							process_wait(t_process *process);

int							process_stdin_default(t_process *process);
int							process_stdout_default(t_process *process);
int							process_stderr_default(t_process *process);
int							process_stdall_default(t_process *process);

int							process_stdin_file(const char *file,
												t_process *process);
int							process_stdout_file(const char *file, int flag,
												t_process *process);
int							process_stderr_file(const char *file, int flag,
												t_process *process);

int							process_stdin_close(t_process *process);
int							process_stdout_close(t_process *process);
int							process_stderr_close(t_process *process);

int							process_pipe(t_process *src, t_process *dst);

void						process_debug(t_process *process, const char *str);
#endif
