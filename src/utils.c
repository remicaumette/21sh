/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 12:54:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 15:30:37 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*ft_strjoinc(char **word, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = *word ? ft_strjoin(*word, m) : ft_strdup(m)))
		return (NULL);
	if (*word)
		ft_strdel(word);
	return (*word = tmp);
}
