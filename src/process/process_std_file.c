/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_file.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:36:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 16:04:17 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		process_stdin_file(const char *file, t_process *process)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ret = FAIL;
		error_access(file, O_RDONLY);
	}
	dup2(fd, process->stdin[0]);
	close(fd);
	process->isset[0] = 1;
	return (ret);
}

int		process_stdout_file(const char *file, int flag, t_process *process)
{
	int		ret;
	int		fd;

	ret = FAIL;
	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
	{
		ret = FAIL;
		error_access(file, O_WRONLY);
	}
	dup2(fd, process->stdout[1]);
	close(fd);
	process->isset[1] = 1;
	return (ret);
}

int		process_stderr_file(const char *file, int flag, t_process *process)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
	{
		ret = FAIL;
		error_access(file, O_WRONLY);
	}
	dup2(fd, process->stderr[1]);
	close(fd);
	process->isset[2] = 1;
	return (ret);
}
