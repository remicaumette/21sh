/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_exit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 10:40:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:30:15 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	print_usage(int std[3])
{
	ft_putstr_fd("21sh: exit: Too many arguments\n", STDERR);
	return (FAIL);
}

int			builtin_exit(int argc, char **argv, int std[3], t_shell *shell)
{
	int		status;

	status = 0;
	if (argc > 2)
		return (print_usage(std));
	else if (argv[1])
		status = ft_atoi(argv[1]);
	shell_destroy(shell);
	exit(status);
	return (SUCCESS);
}
