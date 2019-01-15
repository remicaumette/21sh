/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_histdebug.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:46:42 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 10:22:40 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "history.h"

void		ft_histdebug()
{
	static int		i = -1;
	t_stackhist		*history;

	i++;
	history = ft_hist();
}
