/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_histdebug.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:46:42 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:46:44 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "debug.h"
#include "history.h"


static void		ft_lstnpdebug(const char *path, t_lstnp *node)
{
	static int		nb = 0;
	int				fd;

	if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND | O_TRUNC , S_IRWXU | S_IRWXO)) == -1)
	{
		perror("FAIL lstnp debug");
		return ;
	}
	ft_lstnplog(fd, node, ft_itoa(nb++));
	close(fd);
}

void		ft_histdebug()
{
	static int		i = -1;
	t_stackhist		*history;

	i++;
	history = ft_hist();
	DEBUG_FD("./history.log")
	dprintf(fd, "\n\t\tcall nb=%d\n", i);
	dprintf(fd, "size :%d\n", history->size);
	dprintf(fd, "fist :%s\n", (char *)history->first->data);
	dprintf(fd, "last :%s\n", (char *)history->last->data);
	if (history->tmp)
		dprintf(fd, "tmp  :%s\n", (char *)history->tmp->data);
	else
		dprintf(fd, "tmp  :NULL\n");
	ft_lstnpdebug("./lstnp.log", history->first);
}
