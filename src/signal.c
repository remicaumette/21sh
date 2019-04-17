/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signal.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:54:24 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:32:34 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	SIGINT = CTRL + c
**
**	SIGWINCH = window resize
*/

static void signale_handle(int sig)
{
	if (sig == SIGWINCH)
		term_resize(NULL);
	if (sig == SIGINT)
	{
		ft_putstr("^C\n");
		line_reset(g_shell->line);
		shell_prompt(g_shell);
	}
}

void init_signal(void)
{
	signal(SIGWINCH, signale_handle);
	signal(SIGINT, signale_handle);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
