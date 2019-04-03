/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tc_key.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:41:08 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:25:21 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TC_KEY_H
# define TC_KEY_H

# define TC_KEY_TAB			9
# define TC_KEY_RETURN		10

# define TC_CTRL_A			1
# define TC_CTRL_B			2
# define TC_CTRL_C			3
# define TC_CTRL_D			4
# define TC_CTRL_E			5
# define TC_CTRL_F			6
# define TC_CTRL_I			9
# define TC_CTRL_J			10
# define TC_CTRL_K			11
# define TC_CTRL_L			12
# define TC_CTRL_M			13
# define TC_CTRL_N			14
# define TC_CTRL_Q			17
# define TC_CTRL_R			18

# define TC_KEY_BACKDEL		127

# define TC_KEY_UP			4283163
# define TC_KEY_DOWN		4348699
# define TC_KEY_LEFT		4479771
# define TC_KEY_RIGHT		4414235
# define TC_KEY_END			4610843
# define TC_KEY_HOME		4741915
# define TC_KEY_DEL			2117294875

# define TC_CTRL_RIGHT		73895905418011
# define TC_CTRL_LEFT		74995417045787
# define TC_CTRL_UP			71696882162459
# define TC_CTRL_DOWN		72796393790235

# define TC_GOTO			"cm"
# define TC_NB_COL			"co"
# define TC_NB_LINE			"li"

# define TC_CLEAR			"cl"
# define TC_CLEAR_END_LINE	"ce"
# define TC_CLEAR_TO_END	"cd"

# define TC_DEL				"dc"
# define TC_DEL_LINE		"dl"

# define TC_INSER_START		"im"
# define TC_INSER_STOP		"ei"

# define TC_MOVE_UP			"up"
# define TC_MOVE_DOWN		"do"
# define TC_MOVE_LEFT		"le"
# define TC_MOVE_RIGHT		"nd"

# define TC_GETCURSOR		"\033[6n"
#endif
