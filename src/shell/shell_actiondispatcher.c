/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_actiondispatcher.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:13:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:29:45 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_action	g_actions[] = {
	{TC_KEY_RETURN, action_return},
	{TC_CTRL_A, action_move_first},
	{TC_CTRL_D, action_stop},
	{TC_CTRL_E, action_move_end},
	{TC_CTRL_K, action_clear_to_end},
	{TC_CTRL_L, action_clear},
	{TC_CTRL_R, action_debug},
	{TC_KEY_DEL, action_del},
	{TC_KEY_UP, action_hist_up},
	{TC_KEY_DOWN, action_hist_down},
	{TC_KEY_LEFT, action_move_left},
	{TC_KEY_RIGHT, action_move_right},
	{TC_KEY_END, action_move_end},
	{TC_KEY_HOME, action_move_first},
/*	{TC_CTRL_LEFT, action_move_prev_word},
	{TC_CTRL_RIGHT, action_move_next_word},
	{TC_CTRL_UP, action_move_up},
	{TC_CTRL_DOWN, action_move_down},*/
	{{0, 0, 0}, NULL}
	};


int		action_basic(t_shell *shell, char *buf, int readed)
{
	write(1, buf, readed);
	/*
	if (!(tmp = ft_strjoin(shell->line, buf)))
		return (FAIL);
	write(1, buf, readed);
	ft_strdel(&shell->line);
	shell->line = tmp; */
	return (ft_cursoradd(*buf, shell->cursor));
}
/*
static int	print_debug(t_shell *shell, char *buf, int readed)
{
	(void)shell;
	dprintf(1, "readed=%d\n{%d, %d, %d}\n", readed, buf[0], buf[1], buf[2]);
	dprintf(1, "{%c, %c, %c}\n", buf[0], buf[1], buf[2]);
	write(1, buf, readed);
	return (SUCCESS);
}*/

int			shell_actiondispatcher(t_shell *shell, char *buf, int readed)
{
	t_action	*tmp_action;

	tmp_action = g_actions;
	logdebug(shell->cursor, *buf);
	while (tmp_action->handler != NULL)
	{
		if (ft_memcmp(tmp_action->code, buf, 3) == 0)
			return (tmp_action->handler(shell));
		tmp_action++;
	}
	//return (print_debug(shell, buf, readed));
	return (action_basic(shell, buf, readed));
}
