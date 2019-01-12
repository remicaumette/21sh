/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:20:53 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:22:02 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

/*
********************************************************************************
**								INCLUDES                                      **
********************************************************************************
*/

# include "libft.h"

/*
********************************************************************************
**								DEFINE                                        **
********************************************************************************
*/

# ifndef SUCCESS

#  define SUCCESS		0
#  define FAIL			1

# endif

# define HIST_SIZE_DEFAULT	128

# define FT_HISTNEW			ft_lstnpnew
# define FT_HISTDEL_ONE		ft_lstnpdel_one

# define HIST_STR			(char *)data

/*
********************************************************************************
**								STRUCTURE                                     **
********************************************************************************
*/

typedef t_lstnp		t_hist;

typedef struct		s_stackhist
{
	int				size;
	t_hist			*first;
	t_hist			*last;
	t_hist			*tmp;
}					t_stackhist;

/*
********************************************************************************
**								FONCTIONS                                     **
********************************************************************************
*/

/*
**	in ft_histpush.c
**
**	push new line in history
**
**	Parameters
**	----------
**	str : const char *
**		new line add in history
**
**	Returns
**	-------
**	int :
**		FAIL or SUCCESS
*/
int			ft_histpush(const char *str);

/*
**	in ft_hist.c
**
**	return evry time history
**
**	Returns
**	-------
**	t_stackhist *:
**		ptr of static var t_stackhist
*/
t_stackhist				*ft_hist(void);

/*
**	in ft_histdebug.c
**
**	write t_stackhist in ./history.log
**
*/
void					ft_histdebug();

/*
**	in ft_histget.c
*/
int						ft_histget_up(char **line);
int						ft_histget_down(char **line);

#endif
