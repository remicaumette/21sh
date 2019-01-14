/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:08:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 11:15:54 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include "utils.h"
# include "tc_key.h"
#include "line_edit.h"

typedef struct s_shell		t_shell;
typedef struct s_action		t_action;
typedef struct s_cursor		t_cursor;
typedef int					(*t_actionhandler)(t_shell *);

struct						s_shell
{
	char		**environment;
	char		**history;
	char		*line;
	char		missing_token;
	t_cursor	*cursor;		// remove in the futur 
	t_lexer		*lexer;
	t_parser	*parser;
};

struct						s_action
{
	char			code[3];
	t_actionhandler	handler;
};

extern t_action				g_actions[];
t_shell						*g_shell;


t_shell						*shell_create(char **environment);
void						shell_destroy(t_shell *shell);
int							shell_start(t_shell *shell);
int							shell_actiondispatcher(t_shell *shell, char *buf,
	int readed);
int							shell_processline(t_shell *shell);

/*
**		Prompt
*/
int							shell_prompt(t_shell *shell);

/*
**		Env
*/
int							shell_envinit(t_shell *shell, char **default_env);
char						*shell_getenv(t_shell *shell, char *name);
char						**shell_setenv(t_shell *shell, char *name,
	char *value);
char						**shell_unsetenv(t_shell *shell, char *name);
char						*shell_gethome(t_shell *shell);

/*
**		Action
*/
int							action_return(t_shell *shell);
int							action_clear(t_shell *shell);
int							action_clear_to_end(t_shell *shell);
int							action_del(t_shell *shell);
int							action_hist_up(t_shell *shell);
int							action_hist_down(t_shell *shell);
int							action_move_up(t_shell *shell);
int							action_move_down(t_shell *shell);
int							action_move_left(t_shell *shell);
int							action_move_right(t_shell *shell);
int							action_move_first(t_shell *shell);
int							action_move_end(t_shell *shell);
int							action_move_next_word(t_shell *shell);
int							action_move_prev_word(t_shell *shell);
int							action_stop(t_shell *shell);

//debug need to be del
int							action_debug(t_shell *shell);

// debug
void						print_token(t_token *token);
void						print_node(t_node *node);
#endif
