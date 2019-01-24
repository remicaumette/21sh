/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_prompt.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 09:51:37 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 10:39:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		shell_prompt(t_shell *shell)
{
	char	*pwd;

	if ((pwd = shell_getenv(shell, "PWD")))
		ft_putendl(pwd);
	ft_putstr("$ ");
	return (SUCCESS);
}
