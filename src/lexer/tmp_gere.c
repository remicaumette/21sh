/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:23:56 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lexer.h"

t_tokeninfo	g_tokens[] = {
	{"2>&1", TOKEN_GREATAND_4_TIP, 4},
	{"1>&2", TOKEN_GREATAND_4_TIP, 4},
	{"2>&", TOKEN_GREATAND_3, 3},
	{">&", TOKEN_GREATAND, 2},


	{"<<-", TOKEN_DLESSDASH, 3},
	{"<&", TOKEN_LESSAND, 2},

	{"<>", TOKEN_LESSGREAT, 2},
	{">|", TOKEN_CLOBBER, 2},
	{"|", TOKEN_PIPE, 1},
