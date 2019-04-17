/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   histentry_create.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 15:31:48 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 11:07:02 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_histentry	*histentry_create(char *content)
{
	t_histentry	*histentry;

	ft_sub('\n', ' ', content);
	if (!(histentry = ft_memalloc(sizeof(t_histentry))) ||
		!(histentry->content = ft_strdup(content)))
		return (NULL);
	histentry->prev = NULL;
	histentry->next = NULL;
	return (histentry);
}
