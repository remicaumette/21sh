/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_join.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:25:59 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 20:33:37 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strarr_join(char **arr, char *with)
{
	char	*tmp;
	char	*out;

	if ((tmp = ft_strjoin_2d((const char **)arr)) == NULL)
		return (NULL);
	if ((out = ft_strjoinfree(&tmp, &with, 1)) == NULL)
		return (NULL);
	return (out);
}
