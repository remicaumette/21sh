/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_new.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:55:03 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:55:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strarr_new(size_t size)
{
	char	**out;

	if (!(out = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (size)
	{
		out[size] = NULL;
		size--;
	}
	*out = NULL;
	return (out);
}
