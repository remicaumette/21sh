/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 15:03:14 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tokentype	t_tokentype;
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
