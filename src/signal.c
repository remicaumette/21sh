/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signal.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:54:24 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 13:30:06 by timfuzea    ###    #+. /#+    ###.fr     */
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
		term_resize(NULL);
}

void			init_signal(void)
{
	signal(SIGINT, signale_handl);
	signal(SIGWINCH, signale_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
