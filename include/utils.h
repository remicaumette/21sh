/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 12:55:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 15:02:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef SUCCESS
#  define SUCCESS	0
#  define FAIL		1
# endif

typedef struct s_valise	t_valise;

struct					s_valise
{
	t_shell	*shell;
	char	*token;
	char	*str;
	char	quote;
	int		i;
};

char					*ft_strjoinc(char **word, char c);
#endif
