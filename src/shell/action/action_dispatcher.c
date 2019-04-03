/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_dispatcher.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:25:50 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 10:07:01 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_action	g_actions[] = {
	{TC_KEY_RETURN, action_return},
	{TC_CTRL_A, action_home},
	{TC_CTRL_D, action_stop},
	{TC_CTRL_E, action_end},
	{TC_CTRL_K, action_clear_to_end},
	{TC_CTRL_L, action_clear},
	{TC_KEY_TAB, action_tab},
	{TC_KEY_DEL, action_del},
	{TC_KEY_BACKDEL, action_backdel},
	{TC_KEY_UP, action_arrow_up},
	{TC_KEY_DOWN, action_arrow_down},
	{TC_KEY_LEFT, action_arrow_left},
	{TC_KEY_RIGHT, action_arrow_right},
	{TC_KEY_HOME, action_home},
	{TC_KEY_END, action_end},
	{TC_CTRL_LEFT, action_move_prev_word},
	{TC_CTRL_RIGHT, action_move_next_word},
	{TC_CTRL_UP, action_ctrl_up},
	{TC_CTRL_DOWN, action_ctrl_down},
	{0, NULL}
};

t_ret			action_dispatcher(t_shell *shell, long buf)
{
	t_action	*tmp_action;

	tmp_action = g_actions;
	while (tmp_action->handler != NULL)
	{
		if (tmp_action->key == buf)
			return (tmp_action->handler(shell));
		tmp_action++;
	}
	return (action_basic(shell, buf));
}
