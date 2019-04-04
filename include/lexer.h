/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:25:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "libft.h"

# ifndef SUCCESS
#  define SUCCESS	0
#  define FAIL		1
# endif

typedef enum e_tokentype	t_tokentype;
typedef struct s_shell		t_shell;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;
typedef struct s_tokeninfo	t_tokeninfo;

enum						e_tokentype
{
	TOKEN_WORD,
	TOKEN_NEWLINE,
	TOKEN_PIPE,
	TOKEN_GREAT,
	TOKEN_LESS,
	TOKEN_ANDIF,
	TOKEN_ORIF,
	TOKEN_DSEMI,
	TOKEN_DLESS,
	TOKEN_DGREAT,
	TOKEN_LESSAND,
	TOKEN_GREATAND,
	TOKEN_LESSGREAT,
	TOKEN_DLESSDASH,
	TOKEN_CLOBBER,
	TOKEN_GREAT_2,
	TOKEN_DGREAT_3,
	TOKEN_GREATAND_3,
	TOKEN_GREATAND_3_TIP,
	TOKEN_GREATAND_4,
	TOKEN_GREATAND_4_TIP,
};

struct						s_lexer
{
	t_token			*begin;
	t_token			*end;
	char			quote;
	unsigned int	count;
};

struct						s_token
{
	t_tokentype		type;
	char			*content;
	t_token			*next;
};

struct						s_tokeninfo
{
	char			*format;
	t_tokentype		type;
	unsigned int	len;
};

extern t_tokeninfo			g_tokens[];

int							lexer(t_shell *shell);
t_lexer						*lexer_create(void);
void						lexer_cleanup(t_lexer *lexer);
void						lexer_destroy(t_lexer *lexer);
t_token						*lexer_addtoken(t_lexer *lexer,
	t_tokentype type, char *content);
void						lexer_deltoken(t_token *token);
t_tokentype					lexer_gettype(char *str);
int							lexer_tokenize(t_lexer *lexer, char *str);
char						lexer_getmissingtoken(t_lexer *lexer);
#endif
