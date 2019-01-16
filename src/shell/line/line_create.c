/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:14:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:23:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_line		*line_create(void)
{
	t_line		*line;

	if ((line = malloc(sizeof(t_line))) == NULL)
		return (NULL);
	line->content = NULL;
	line->size = 0;
	line->cursor = 1;
	if (get_winsize(&(line->window)) != SUCCESS)
		return (NULL);
	return (line);
}
