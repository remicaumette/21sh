/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:54:04 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:54:06 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *mem, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		return (NULL);
	ft_memcpy(tmp, mem, size);
	return (tmp);
}
