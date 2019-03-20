/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:38:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:38:58 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_term		*term_create(t_shell *shell)
{
	t_term		*term;

	if ((term = malloc(sizeof(t_term))) == NULL)
		return (NULL);
	if ((term->save = malloc(sizeof(struct termios))) == NULL)
		return (NULL);
	if (tgetent(NULL, shell_getenv(shell, "TERM")) == -1)
		return (NULL);
	if (tcgetattr(0, term->save) == -1)
		return (NULL);
	if (!(term->my = ft_memdup((void *)term->save, sizeof(struct termios))))
		return (NULL);
	term->my->c_lflag &= ~(ICANON);
	term->my->c_lflag &= ~(ECHO);
	term->my->c_cc[VMIN] = 1;
	term->my->c_cc[VTIME] = 0;
	return (term);
}
