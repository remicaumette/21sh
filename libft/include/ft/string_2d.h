/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string_2d.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 14:14:44 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 14:18:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRING_2D_H
# define STRING_2D_H


#include <stdlib.h>

#include "libft.h"

char		**ft_strnew_2d(size_t size);
void		ft_strdel_2d(char ***as);
size_t		ft_strlen_2d(const char **str);

char		**ft_strdup_2d(const char **str);
int			ft_strequ_2d(const char **s1, const char **s2);
char		*ft_strjoinspace_2d(const char **str);
#endif
