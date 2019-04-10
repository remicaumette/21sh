/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strpp.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 12:14:32 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 23:26:43 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*up(char **str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*str) + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strdel(str);
	*str = tmp;
	*tmp = '1';
	tmp++;
	len--;
	while (len)
	{
		*tmp = '0';
		tmp++;
		len--;
	}
	return (*str);
}

char		*ft_strpp(char **str)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *str;
	if (ft_str_isdigit(tmp))
		return (NULL);
	while (tmp[i])
		i++;
	i--;
	if (tmp[i] != '9')
	{
		tmp[i]++;
		return (*str);
	}
	while (i > 0 && tmp[i] == '9')
		i--;
	if (i != 0)
	{
		tmp[i]++;
		while (tmp[++i])
			tmp[i] = '0';
		return (*str);
	}
	return (up(str));
}
