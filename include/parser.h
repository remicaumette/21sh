/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 09:55:18 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "libft.h"

# ifndef SUCCESS
#  define SUCCESS		0
#  define FAIL			1
# endif

typedef enum e_nodetype			t_nodetype;
typedef struct s_parser			t_parser;
typedef struct s_node			t_node;
typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;
typedef struct s_shell			t_shell;

struct							s_parser
{
	t_node		*root;
	t_token		*curr;
};

struct							s_node
{
	t_tokentype	type;
	t_command	*command;
	t_node		*next;
};

struct							s_command
{
	char			*name;
	char			**arguments;
	t_redirection	*redirection;
};

struct							s_redirection
{
	t_tokentype		type;
	char			*symbols;
	char			*file;
	t_redirection	*next;
};

t_parser						*parser_create(void);
void							parser_destroy(t_parser **as);
void							parser_cleanup(t_parser *parser);
int								parser_parse(t_shell *shell);

t_node							*node_create(t_tokentype type,
												t_command *command);
void							node_destroy(t_node **as);
void							node_insert(t_node **root, t_node *node);

t_command						*command_create(char *name);
void							command_destroy(t_command **as);
t_command						*command_parse(t_parser *parser);

t_redirection					*redirection_create(t_tokentype type,
													char *symbols, char *file);
void							redirection_destroy(t_redirection **as);
int								redirection_parse(t_redirection **redirection,
													t_parser *parser);

int								token_isredirection(t_tokentype type);
int								token_isfile_redir(t_tokentype type);

#endif
