/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:31:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:24:17 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

// int			main(int argc, char **argv, char **environment)
// {
// 	(void)argc;
// 	(void)argv;
// 	if (!(g_shell = shell_create(environment)) || shell_start(g_shell))
// 		return (1);
// 	shell_destroy(g_shell);
// 	return (0);
// }

int	main(void)
{
	t_process	*process;
	char		**env;
	char		**args;

	env = NULL;
	args = NULL;
	env = ft_strarr_add(env, "LSCOLORS=Gxfxcxdxbxegedabagacad");
	args = ft_strarr_add(args, "-a");
	process = process_create("/bin/ls", args, env);

	ft_strarr_del(env);
	ft_strarr_del(args);
	process_destroy(process);
}
