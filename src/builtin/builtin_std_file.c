/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_std_file.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:31:34 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:43:45 by timfuzea    ###    #+. /#+    ###.fr     */
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
		close(builtin->STDIN);
	}
	else
	{
		if (builtin_stdin_dup(fd, builtin) != SUCCESS)
			ret = FAIL;
		close(fd);
	}
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
		close(builtin->STDOUT);
	}
	else
	{
		if (builtin_stdout_dup(fd, builtin) != SUCCESS)
			ret = FAIL;
		close(fd);
	}
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
		close(builtin->STDERR);
	}
	else
	{
		if (builtin_stderr_dup(fd, builtin) != SUCCESS)
			ret = FAIL;
		close(fd);
	}
	return (ret);
}
