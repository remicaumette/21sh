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

void		action_putchar(t_shell *shell, char buf)
{
	write(1, &buf, 1);
	if (IS_ENDLINE)
	{
		ft_putchar('\n');
		if (!IS_LASTLINE)
			CURENT_ROW++;
		CURENT_COL = 1;
	}
	else
		CURENT_COL++;
}

void		action_putstr(t_shell *shell, char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			action_putchar(shell, *str);
			str++;
		}
	}
}
