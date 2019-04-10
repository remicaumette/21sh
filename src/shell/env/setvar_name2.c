/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setvar_name2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:41:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 23:42:26 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		setvar_pwd(t_shell *shell)
{
	char	*pwd;

	pwd = NULL;
	if ((pwd = get_pwd(64)) == NULL)
		return (FAIL);
	shell_setenv(shell, "PWD", pwd);
	ft_strdel(&pwd);
	return (SUCCESS);
}
