/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hist.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 15:30:16 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:30:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_stackhist		*hist(void)
{
	static t_stackhist		history = {0, NULL, NULL, NULL};

	return (&history);
}
