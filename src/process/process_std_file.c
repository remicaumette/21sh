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
		close(process->STDIN);
	}
	else
	{
		if (process_stdin_dup(fd, process) == -1)
			ret = FAIL;
		close(fd);
	}
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
		close(process->STDOUT);
	}
	else
	{
		if (process_stdout_dup(fd, process) == -1)
			ret = FAIL;
		close(fd);
	}
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
		close(process->STDERR);
	}
	else
	{
		if (process_stderr_dup(fd, process) == -1)
			ret = FAIL;
		close(fd);
	}
	return (ret);
}
