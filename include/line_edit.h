/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_edit.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 15:59:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:46:26 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LINE_EDIT_H
# define LINE_EDIT_H

/*
********************************************************************************
**								INCLUDES                                      **
********************************************************************************
*/

# include <curses.h>
# include <term.h>
# include <unistd.h>
# include "tc_key.h"
#include "debug.h"
# include "lChar.h"
#include "shell.h"
#include "history.h"
/*
********************************************************************************
**								DEFINE                                        **
********************************************************************************
*/

# ifndef SUCCESS

#  define SUCCESS		1
#  define FAIL			0

# endif

# define STOP			-1
# define END			-2
# define EGAIN			-3

# define SET			3
# define GET			4

# define TC_NB_COL		"co"
# define TC_NB_LINE		"li"

# define TC_CLEAR		"cl"
# define TC_CLEAR_TO_END "ce"

# define TC_DEL			"dc"
# define TC_DEL_LINE	"dl"

# define TC_INSER_START	"im"
# define TC_INSER_STOP	"ei"

# define TC_MOVE_UP		"up"
# define TC_MOVE_DOWN	"do"
# define TC_MOVE_LEFT	"le"
# define TC_MOVE_RIGHT	"nd"

# define TC_GETPOS		"\033[6n"

/*
**	Flag for ft_cursor.c
*/

# define CUR_SET_CURRENT	0x0001
# define CUR_SET_WINSIZE	0x0002
# define CUR_SET_ALL		0x0003

# define CUR_RESET			0x4000
# define CUR_FREE			0x8000
/*
********************************************************************************
**								STRUCTURE                                     **
********************************************************************************
*/

typedef unsigned int	t_flag;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_cursor
{
	t_point			pos;
	t_point			*winsize;
	t_lChar			*current;
	t_lChar			*first;
	t_lChar			*last;
	int				dist_first;
	int				dist_last;
}					t_cursor;

typedef struct		s_tc_action
{
	long			key;
	int				(*fn)(t_cursor *);
}					t_tc_action;

/*
********************************************************************************
**								FUNCTIONS                                     **
********************************************************************************
*/

/*
**		in logdebug.c
*/
void				logdebug(t_cursor * cursor, char c);

/*
**		in init_line.c
*/
int					init_line(void);

/*
**		in exit_line.c
*/
void				exit_line(void);

/*
**		in get_line.c
*/
int					get_line(char **line);
long				get_char(void);
int					do_stuff_key(long buf, t_cursor *cursor);

/*
**		in ft_winsize.c
*/
t_point				*ft_winsize(int action);
void					ft_winpos(t_point *pos);


/*
**				Action Part
*/

/*
**		in action_tab.c
*/
t_tc_action			*get_action_tab(void);
/*
**		in ft_cursor.c
*/
t_cursor			*ft_cursor(t_flag action);

/*
**		in ft_cursorinit.c
*/
void				ft_cursorinit(t_cursor *cursor);

/*
**		in ft_cursordel_all.c
*/
void				ft_cursordel_all(t_cursor **cursor);

/*
**		in ft_cursoradd.c
*/
int					ft_cursoradd(char buf, t_cursor *cursor);

/*
**		in ft_cursordel_current.c
*/
void				ft_cursordel_current(t_cursor *cursor);

/*
**		in ft_cursordel_toend.c
*/
void				ft_cursordel_toend(t_cursor *cursor);

/*
**		in ft_cursorinser.c
*/
void				ft_cursorinser(t_lChar *new, t_cursor *cursor);

#endif
