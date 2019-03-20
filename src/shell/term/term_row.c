/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term_row.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:39:08 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:39:33 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			term_row_start(t_shell *shell)
{
	if (tcsetattr(0, TCSANOW, shell->term->my) == -1)
		return (FAIL);
	return (SUCCESS);
}

int			term_row_stop(t_shell *shell)
{
	if (action_str(TC_INSER_STOP) != SUCCESS)
		return (FAIL);
	if (tcsetattr(0, 0, shell->term->save) == -1)
		return (FAIL);
	return (SUCCESS);
}
