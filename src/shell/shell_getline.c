/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_getline.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:40:48 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:41:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		shell_getline(t_shell *shell)
{
	int		readed;
	t_ret	ret;
	long	buf;

	buf = 0;
	term_row_start(shell);
	if (term_getcurentpos(&shell->line->cur_pos) != SUCCESS)
	{
		term_row_stop(shell);
		return (FAIL);
	}
	while ((readed = read(0, &buf, sizeof(buf))) > 0)
	{
		if ((ret = action_dispatcher(shell, buf)) != RET_EGAIN)
			break ;
		buf = 0;
	}
	term_row_stop(shell);
	return (ret);
}
