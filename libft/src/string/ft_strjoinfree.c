/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:55:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:27:42 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char **s1, char **s2, int i)
{
	char		*tmp;

	tmp = NULL;
	if (*s1 && *s2)
		tmp = ft_strjoin(*s1, *s2);
	else if (*s1)
		tmp = ft_strdup(*s1);
	else if (*s2)
		tmp = ft_strdup(*s2);
	if (i == 1 || i == 3)
		ft_strdel(s1);
	if (i == 2 || i == 3)
		ft_strdel(s2);
	return (tmp);
}
