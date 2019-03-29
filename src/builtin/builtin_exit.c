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

void		builtin_exit(char **argv, t_shell *shell)
{
	int		status;

	status = 0;
	if (argv[0] && argv[1])
	{
		ft_putstr_fd("21sh: exitL Too many arguments\n", STDERR_FILENO);
		return ;
	}
	else if (argv[0])
		status = ft_atoi(argv[0]);
	shell_destroy(shell);
	exit(status);
}
