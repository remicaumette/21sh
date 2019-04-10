/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stradd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 19:56:22 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 22:05:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_stradd_2d(const char **ref, const char *new)
{
	char		**out;
	char		**tmp;
	size_t		len_ref;

	len_ref = ft_strlen_2d(ref);
	if ((out = ft_strnew_2d(len_ref + 1)) == NULL)
		return (NULL);
	tmp = out;
	if (ref)
	{
		while (*ref)
		{
			if ((*tmp = ft_strdup(*ref)) == NULL)
				return (NULL);
			tmp++;
			ref++;
		}
	}
	if ((*tmp = ft_strdup(new)) == NULL)
		return (NULL);
	tmp++;
	tmp = NULL;
	return (out);
}

char		**ft_straddfree_2d(char ***ref, char **new, int i)
{
	char		**out;

	if ((out = ft_stradd_2d((const char **)*ref, (const char *)*new)) == NULL)
		return (NULL);
	if (i == 1 || i == 3)
		ft_strdel_2d(ref);
	if (i == 2 || i == 3)
		ft_strdel(new);
	return (out);
}
