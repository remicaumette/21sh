/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstnp.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 17:38:43 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 17:39:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LSTNP_H
# define LSTNP_H

# include <stdlib.h>
// debug
# include <stdio.h>

typedef struct		s_lstnp
{
	void			*data;
	struct s_lstnp	*next;
	struct s_lstnp	*prev;
}					t_lstnp;

t_lstnp				*ft_lstnpnew(void *data);
void				ft_lstnpdel_one(t_lstnp **as, void (*del)(void *));

// use dprintf
void				ft_lstnplog(int fd, t_lstnp *begin_lst,
		const char *head_msg);
#endif
