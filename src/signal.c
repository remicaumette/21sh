/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signal.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:54:24 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/28 22:07:01 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	SIGINT = CTRL + c
**
**	SIGWINCH = window resize
*/

static void		signale_handl(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("SIG_INT recu\n");
		exit(1);
	}
	if (sig == SIGWINCH)
	{
		ft_putstr("SIG_WINCH == redimension windo\n");
		re_size(NULL);
	}
	dprintf(1, "sig=%d\n", sig);
}

void			init_signal(void)
{
	signal(SIGINT, signale_handl);
	signal(SIGWINCH, signale_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
