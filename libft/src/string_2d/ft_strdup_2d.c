/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup_2d.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:55 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_2d(const char **str)
{
	char	**out;
	char	**pt_out;
	size_t	len;

	len = ft_strlen_2d(str);
	if ((out = ft_strnew_2d(len)) == NULL)
		return (NULL);
	pt_out = out;
	while (len)
	{
		if ((*pt_out = ft_strdup(*str)) == NULL)
			return (NULL);
		pt_out++;
		str++;
		len--;
	}
	*pt_out = NULL;
	return (out);
}
