/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lChar.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 14:34:18 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 14:34:20 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LCHAR_H
# define LCHAR_H


/*
********************************************************************************
**								INCLUDES                                      **
********************************************************************************
*/

#include <stdlib.h>

#include "libft.h"

/*
********************************************************************************
**								DEFINE                                        **
********************************************************************************
*/


/*
********************************************************************************
**								STRUCTUR                                      **
********************************************************************************
*/

typedef struct		s_lChar
{
	char			c;
	struct s_lChar	*next;
	struct s_lChar	*prev;
}					t_lChar;

/*
********************************************************************************
**								FUNCTION                                      **
********************************************************************************
*/

/*
**	in ft_lCharNew.c
*/
t_lChar				*ft_lCharnew(char c);

/*
**	in ft_lCharDel.c
*/
void				ft_lChardel_one(t_lChar **begin_lst, t_lChar **as);
void				ft_lChardel_all(t_lChar **begin_lst_as);

/*
**	in ft_lCharLen.c
*/
size_t				ft_lCharlen(t_lChar *begin_lst);

/*
**	in ft_lCharfirst.c
*/
t_lChar				*ft_lCharfirst(t_lChar *node);

/*
**	in ft_lCharlast.c
*/
t_lChar				*ft_lCharlast(t_lChar *node);

/*
**	in ft_lCharpush.c
*/
void				ft_lCharpush_front(t_lChar **begin_lst, t_lChar *node);
void				ft_lCharpush_back(t_lChar **begin_lst, t_lChar *node);

/*
**	in ft_lCharTostr.c
*/
char				*ft_lCharto_str(t_lChar *node);

#endif
