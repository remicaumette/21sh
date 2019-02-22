/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_utile.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 12:41:18 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 18:42:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			action_str(char *cap)
{
	char	*tmp;

	if (!(tmp = tgetstr(cap, NULL)))
		return (FAIL);
	ft_putstr(tmp);
	return (SUCCESS);
}

void		action_putchar(t_line *line, char buf)
{
	write(1, &buf, 1);
	if (IS_ENDLINE)
	{
		ft_putchar('\n');
		if (!IS_LASTLINE)
			line->cur_pos.ws_row++;
		line->cur_pos.ws_col = 1;
	}
	else
		line->cur_pos.ws_col++;
}

void		action_putstr(t_line *line, char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			action_putchar(line, *str);
			str++;
		}
	}
}
