/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 14:13:22 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 14:13:27 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_sub(const char ref, const char new, char *str)
{
	while (*str)
	{
		if (*str == ref)
			*str = new;
		str++;
	}
}
