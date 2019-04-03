/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:14:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:59:10 by timfuzea    ###    #+. /#+    ###.fr     */
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
	line->cur_pos.ws_row = 0;
	line->cur_pos.ws_col = 0;
	line->window.ws_row = 0;
	line->window.ws_col = 0;
	return (line);
}
