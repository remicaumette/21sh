/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 14:39:45 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_clear(t_shell *shell)
{
	char	*tmp;

	if ((tmp = tgetstr(TC_CLEAR, NULL)) == NULL)
		return (FAIL);
	ft_putstr(tmp);
	shell_prompt(shell);
	ft_putstr(shell->line->content);
	return (SUCCESS);
}

int		action_clear_to_end(t_shell *shell)
{
	char	*tmp;

	if (shell->line->cursor < (shell->line->size + 1))
	{
		if ((tmp = tgetstr(TC_CLEAR_TO_END, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		line_deltoend(shell->line);
	}
	return (SUCCESS);
}
