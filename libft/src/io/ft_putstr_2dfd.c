/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_2dfd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:52 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:52 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_2dfd(char **str, int fd)
{
	while (*str)
	{
		write(fd, *str, ft_strlen(*str));
		write(fd, "\n", 1);
		str++;
	}
}
