/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_std_file.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:31:34 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:31:47 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		builtin_stdin_file(const char *file, t_builtin *builtin)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ret = FAIL;
		error_access(file, O_RDONLY);
		close(builtin->std[STDIN]);
	}
	else
	{
		if (builtin_stdin_dup(fd, builtin) != SUCCESS)
			ret = FAIL;
		close(fd);
	}
	builtin->isset[STDIN] = 1;
	return (ret);
}

int		builtin_stdout_file(const char *file, int flag, t_builtin *builtin)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
	{
		ret = FAIL;
		error_access(file, O_WRONLY);
		close(builtin->std[STDOUT]);
	}
	else
	{
		if (builtin_stdout_dup(fd, builtin) != SUCCESS)
			ret = FAIL;
		close(fd);
	}
	builtin->isset[STDOUT] = 1;
	return (ret);
}

int		builtin_stderr_file(const char *file, int flag, t_builtin *builtin)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
	{
		ret = FAIL;
		error_access(file, O_WRONLY);
		close(builtin->std[STDERR]);
	}
	else
	{
		if (builtin_stderr_dup(fd, builtin) != SUCCESS)
			ret = FAIL;
		close(fd);
	}
	builtin->isset[STDERR] = 1;
	return (ret);
}
