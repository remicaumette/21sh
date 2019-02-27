/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:08:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:06:52 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# include "debug.h"
# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include "process.h"
# include "utils.h"
# include "tc_key.h"

# ifdef __linux__
#  define LINUX				1
# else
#  define LINUX				0
# endif

# define CURSOR				shell->line->cursor
# define CURENT_COL			shell->line->cur_pos.ws_col
# define CURENT_ROW			shell->line->cur_pos.ws_row

# define MAX_COL			shell->line->window.ws_col
# define MAX_ROW			shell->line->window.ws_row

# define IS_ENDLINE			(CURENT_COL >= MAX_COL)
# define IS_LASTLINE		(CURENT_ROW >= MAX_ROW)

typedef struct s_shell		t_shell;
typedef struct s_action		t_action;
typedef struct s_line		t_line;
typedef struct s_history	t_history;
typedef struct s_histentry	t_histentry;
typedef struct winsize		t_winsize;
typedef int					(*t_actionhandler)(t_shell *);

struct						s_shell
{
	char		**environment;
	char		missing_token;
	t_line		*line;
	t_history	*history;
	t_lexer		*lexer;
	t_parser	*parser;
};

struct						s_action
{
	long			key;
	t_actionhandler	handler;
};

struct						s_line
{
	char		*content;
	int			size;
	int			cursor;
	t_winsize	cur_pos;
	t_winsize	window;
};

struct						s_history
{
	int			size;
	t_histentry	*begin;
	t_histentry	*curr;
	t_histentry	*end;
};

struct						s_histentry
{
	t_histentry	*prev;
	char		*content;
	t_histentry	*next;
};

extern t_action				g_actions[];
t_shell						*g_shell;

void						init_signal(void);

t_shell						*shell_create(char **environment);
void						shell_destroy(t_shell *shell);
int							shell_start(t_shell *shell);
int							shell_actiondispatcher(t_shell *shell, long buf);
int							shell_processline(t_shell *shell);
int							shell_prompt(t_shell *shell);
int							shell_envinit(t_shell *shell, char **default_env);
char						*shell_getenv(t_shell *shell, char *name);
char						**shell_setenv(t_shell *shell, char *name,
	char *value);
char						**shell_unsetenv(t_shell *shell, char *name);
char						*shell_gethome(t_shell *shell);

void						window_resize(t_shell *shell);
int							window_getcurentpos(t_winsize *curent_pos);

t_history					*history_create(void);
void						history_destroy(t_history *history);
t_histentry					*histentry_create(char *content);
void						histentry_destroy(t_histentry *entry);
t_histentry					*history_insert(t_history *history, char *line);

t_line						*line_create(void);
void						line_destroy(t_line **line);
void						line_reset(t_line *line);
int							line_inser(t_line *line, char c);
int							line_deltoend(t_line *line);
int							line_backdel(t_line *line);
void						line_replace(t_line *line, char *src);
int							line_curpp(t_line *line, int n);
int							line_debug(t_line *line);

int							action_debug(t_shell *shell);

int							action_str(char *cap);
void						action_putchar(t_shell *shell, char buf);
void						action_putstr(t_shell *shell, char *str);

int							action_move_left(t_shell *shell);
int							action_move_right(t_shell *shell);

int							action_basic(t_shell *shell, long buf);
int							action_return(t_shell *shell);
int							action_clear(t_shell *shell);
int							action_clear_to_end(t_shell *shell);
int							action_backdel(t_shell *shell);
int							action_arrow_up(t_shell *shell);
int							action_arrow_down(t_shell *shell);
int							action_arrow_left(t_shell *shell);
int							action_arrow_right(t_shell *shell);
int							action_home(t_shell *shell);
int							action_end(t_shell *shell);
int							action_move_next_word(t_shell *shell);
int							action_move_prev_word(t_shell *shell);
int							action_ctrl_up(t_shell *shell);
int							action_ctrl_down(t_shell *shell);
int							action_stop(t_shell *shell);

void						print_token(t_token *token);
void						print_node(t_node *node);
#endif
