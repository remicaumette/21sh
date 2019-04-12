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

static void		signale_handl(int sig)
{
	if (sig == SIGWINCH)
		term_resize(NULL);
}

void			init_signal(void)
{
	signal(SIGWINCH, signale_handl);
	signal(SIGINT, signale_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
