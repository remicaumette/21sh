/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnplog.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 17:32:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 17:37:55 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lstnp.h"

/*
**	write all list in file
**	data is cast in char
**	Warnige circular lst = loop
**
**	Parametres
**	----------
**	fd : int
**		file descriptor returned by open
**	begin_lst : t_lstnp *
**		list to print in file
**	head_msg : const char *
**		msg to print in first line of debug
*/

static inline void	print_head(int fd, const char *head_msg)
{
	dprintf(fd, "\n\t\t Debug t_lstnp\n");
	dprintf(fd, "\t\t%s\n", head_msg);
}

static inline void	print_body(int fd, int i, t_lstnp *tmp)
{
	dprintf(fd, "\n\tNode %p\n", tmp);
	dprintf(fd, "nb   :%d\n", i);
	dprintf(fd, "data :%s\n", (char *)tmp->data);
	dprintf(fd, "next :%p\n", tmp->next);
	dprintf(fd, "prev :%p\n", tmp->prev);
	dprintf(fd, "\tEnd node\n");
}

void				ft_lstnplog(int fd, t_lstnp *begin_lst,
		const char *head_msg)
{
	int			i;
	t_lstnp		*tmp;

	i = 0;
	tmp = begin_lst;
	print_head(fd, head_msg);
	if (begin_lst == NULL)
		dprintf(fd, "*begin_lst == NULL\n");
	while (tmp)
	{
		print_body(fd, i, tmp);
		if (tmp == tmp->next || tmp->next == begin_lst)
		{
			dprintf(fd, "Waring loop detected stop print\n");
			break ;
		}
		tmp = tmp->next;
		i++;
	}
}
