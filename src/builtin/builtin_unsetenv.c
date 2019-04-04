/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_unsetenv.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:31:16 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:31:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		builtin_unsetenv(int argc, char **argv, int std[3], t_shell *shell)
{
	int		i;

	(void)std;
	i = 0;
	while (++i < argc)
	{
		if (!shell_unsetenv(shell, argv[i]))
			return (FAIL);
	}
	return (SUCCESS);
}
