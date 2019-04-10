/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 12:54:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 19:12:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char		*ft_strjoinc(char **word, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = *word ? ft_strjoin(*word, m) : ft_strdup(m)))
		return (NULL);
	if (*word)
		ft_strdel(word);
	return (*word = tmp);
}

int			print_error(const char *path, const char *err_msg)
{
	ft_putstr_fd("21sh: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(path, STDERR_FILENO);
	return (FAIL);
}

int			error_access(const char *path, int right)
{
	if (right & O_RDONLY)
	{
		if (access(path, F_OK))
			return (print_error(path, "No such file or directory"));
		else if (access(path, R_OK))
			return (print_error(path, "Permission denide"));
		else
			return (print_error(path, "Unexpected error"));
	}
	else if (right & O_WRONLY)
	{
		if (access(path, F_OK))
			return (print_error(path, "No such file or directory"));
		else if (access(path, W_OK))
			return (print_error(path, "Permission denide"));
		else if (!access(path, F_OK))
			return (print_error(path, "Is not a file"));
		else
			return (print_error(path, "Unexpected error"));
	}
	else
		return (print_error(path, "Unexpected error"));
	return (FAIL);
}
