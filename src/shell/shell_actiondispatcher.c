/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_actiondispatcher.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:13:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:28:52 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_action	g_actions[] = {
	{{27, 91, 65}, action_arrowup},
	{{10, 0, 0}, action_return},
};


int		action_basic(t_shell *shell, char *buf, int readed)
{
	char*tmp;

	if (!(tmp = ft_strjoin(shell->line, buf)))
		return (FAIL);
	write(1, buf, readed);
	ft_strdel(&shell->line);
	shell->line = tmp;
	return (SUCCESS);
}


int			shell_actiondispatcher(t_shell *shell, char *buf, int readed)
{
	int	i;

	i = -1;
	while (++i < 2)
		if (ft_memcmp(g_actions[i].code, buf, 3) == 0)
			return (g_actions[i].handler(shell));
	return (action_basic(shell, buf, readed));
}
