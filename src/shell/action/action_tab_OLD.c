/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:26:08 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 14:26:40 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

t_tc_action			*get_action_tab(void)
{
	static t_tc_action		out[] = {
		{'\n', &action_return},
		{TC_CTRL_A, action_move_first},
		{TC_CTRL_D, action_stop},
		{TC_CTRL_E, action_move_end},
		{TC_CTRL_K, action_clear_to_end},
		{TC_CTRL_L, action_clear},
		{TC_CTRL_R, action_debug},
		{TC_KEY_LEFT, action_move_left},
		{TC_KEY_RIGHT, action_move_right},
		{TC_KEY_DEL, action_del},
		{TC_KEY_HOME, action_move_first},
		{TC_KEY_END, action_move_end},
		{TC_CTRL_LEFT, action_move_prev_word},
		{TC_CTRL_RIGHT, action_move_next_word},
		{TC_CTRL_UP, action_move_up},
		{TC_CTRL_DOWN, action_move_down},
		{TC_KEY_UP, action_hist_up},
		{TC_KEY_DOWN, action_hist_down},
		{0, NULL}
	};

	return (out);
}
