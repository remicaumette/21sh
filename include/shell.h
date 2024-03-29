/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:08:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 13:12:19 by timfuzea    ###    #+. /#+    ###.fr     */
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
# include <sys/types.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <dirent.h>

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

# define SHELL_NAME			"21sh"

# define CURSOR				shell->line->cursor
# define CURENT_COL			shell->line->cur_pos.ws_col
# define CURENT_ROW			shell->line->cur_pos.ws_row

# define MAX_COL			shell->line->window.ws_col
# define MAX_ROW			shell->line->window.ws_row

# define IS_ENDLINE			(CURENT_COL >= MAX_COL)
# define IS_LASTLINE		(CURENT_ROW >= MAX_ROW)

# define BUFF_PWD			64

# define STDIN				std[0]
# define STDOUT				std[1]
# define STDERR				std[2]

typedef struct stat			t_stat;
typedef struct passwd		t_passwd;
typedef struct s_shell		t_shell;
typedef struct s_action		t_action;
typedef struct s_line		t_line;
typedef struct s_history	t_history;
typedef struct s_histentry	t_histentry;
typedef struct winsize		t_winsize;
typedef struct s_eval		t_eval;
typedef struct s_term		t_term;
typedef struct s_builtin	t_builtin;
typedef int					(*t_func_builtin)(int argc, char **argv,
								int std[3], t_shell *shell);
typedef struct s_buil_tab	t_buil_tab;
typedef enum e_ret			t_ret;
typedef t_ret				(*t_actionhandler)(t_shell *);

enum						e_ret
{
	RET_SUCCESS,
	RET_STOP,
	RET_EGAIN,
	RET_FAIL,
};

struct						s_builtin
{
	char				**argv;
	int					std[3];
	int					out_to_err;
	int					err_to_out;
	t_func_builtin		func;
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

struct						s_buil_tab
{
	char				*str;
	t_func_builtin		func;
};

struct						s_history
{
	int			size;
	char		*tmp;
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

struct						s_term
{
	struct termios		*my;
	struct termios		*save;
};

struct						s_eval
{
	t_builtin			*builtin;
	t_process			*process;
	t_eval				*next;
};

struct						s_shell
{
	char		**environment;
	char		missing_token;
	int			kill;
	char		*kill_str;
	t_line		*line;
	t_history	*history;
	t_lexer		*lexer;
	t_parser	*parser;
	t_eval		*eval;
	t_term		*term;
};

extern t_action				g_actions[];
t_shell						*g_shell;

void						init_signal(void);

t_shell						*shell_create(char **environment);
void						shell_destroy(t_shell *shell);
int							shell_start(t_shell *shell);
int							shell_processline(t_shell *shell);
int							shell_prompt(t_shell *shell);
int							shell_envinit(t_shell *shell, char **default_env);
char						*shell_getenv(t_shell *shell, char *name);
char						**shell_setenv(t_shell *shell, char *name,
	char *value);
char						**shell_unsetenv(t_shell *shell, char *name);
int							env_setall(char *all, t_shell *shell);
t_ret						shell_getline(t_shell *shell);
int							env_default_path(char **path);
int							env_getpw(t_passwd **pw);

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
int							line_del(t_line *line);
int							line_backdel(t_line *line);
void						line_replace(t_line *line, char *src);
int							line_curpp(t_line *line, int n);
int							line_debug(t_line *line);

t_ret						action_dispatcher(t_shell *shell, long buf);
t_ret						action_debug(t_shell *shell);

int							action_str(char *cap);
void						action_putchar(t_shell *shell, char buf);
void						action_putstr(t_shell *shell, char *str);

int							action_move_left(t_shell *shell);
int							action_move_right(t_shell *shell);

t_ret						action_basic(t_shell *shell, long buf);
t_ret						action_return(t_shell *shell);
t_ret						action_clear(t_shell *shell);
t_ret						action_clear_to_end(t_shell *shell);
t_ret						action_del(t_shell *shell);
t_ret						action_backdel(t_shell *shell);
t_ret						action_arrow_up(t_shell *shell);
t_ret						action_arrow_down(t_shell *shell);
t_ret						action_arrow_left(t_shell *shell);
t_ret						action_arrow_right(t_shell *shell);
t_ret						action_home(t_shell *shell);
t_ret						action_end(t_shell *shell);
t_ret						action_move_next_word(t_shell *shell);
t_ret						action_move_prev_word(t_shell *shell);
t_ret						action_ctrl_up(t_shell *shell);
t_ret						action_ctrl_down(t_shell *shell);
t_ret						action_stop(t_shell *shell);
t_ret						action_tab(t_shell *shell);

void						print_token(t_token *token);
void						print_node(t_node *node);

t_term						*term_create(t_shell *shell);
void						term_destroy(t_term **term);
int							term_row_start(t_shell *shell);
int							term_row_stop(t_shell *shell);

void						term_resize(t_shell *shell);
int							term_getcurentpos(t_winsize *curent_pos);

t_builtin					*builtin_create(char **argv, t_func_builtin func);
void						builtin_destroy(t_builtin **as);
int							builtin_exit(int argc, char **argv, int std[3],
											t_shell *shell);
int							builtin_env(int argc, char **argv, int std[3],
											t_shell *shell);
int							builtin_setenv(int argc, char **argv, int std[3],
											t_shell *shell);
int							builtin_unsetenv(int argc, char **argv, int std[3],
											t_shell *shell);
int							builtin_echo(int argc, char **argv, int std[3],
											t_shell *shell);
int							cd_home(t_shell *shell, int std[3]);
int							builtin_cd(int argc, char **argv, int std[3],
											t_shell *shell);
int							cd_oldpwd(t_shell *shell, int std[3]);
int							cd_tild(t_shell *shell, char *path, int std[3]);
int							ft_chdir(char *path, int str[3]);
char						*get_pwd(int buf_size);

int							builtin_stdin_close(t_builtin *builtin);
int							builtin_stdout_close(t_builtin *builtin);
int							builtin_stderr_close(t_builtin *builtin);
int							builtin_stdall_close(t_builtin *builtin);

int							builtin_stdin_default(t_builtin *builtin);
int							builtin_stdout_default(t_builtin *builtin);
int							builtin_stderr_default(t_builtin *builtin);
int							builtin_stdall_default(t_builtin *builtin);
int							builtin_stdall_default_isset(t_builtin *builtin);

int							builtin_stdin_dup(int stdin, t_builtin *builtin);
int							builtin_stdout_dup(int stdout, t_builtin *builtin);
int							builtin_stderr_dup(int stderr, t_builtin *builtin);
int							builtin_stdall_dup(int std[3], t_builtin *builtin);

int							builtin_stdin_file(const char *file,
												t_builtin *builtin);

int							builtin_stdout_file(const char *file, int flag,
													t_builtin *builtin);
int							builtin_stderr_file(const char *file, int flag,
													t_builtin *builtin);

t_eval						*eval_create(t_builtin *builtin,
										t_process *process);
int							eval_destroy(t_eval **eval);

int							run_eval(t_eval *eval, t_shell *shell);
int							eval_all(t_shell *shell);
int							eval_line(t_node *curr, t_shell *shell);
int							eval_command(t_node *node,
											t_eval **eval, t_shell *shell);
int							eval_process_redirection(t_command *command,
										t_process *process, t_shell *shell);
int							eval_builtin_redirection(t_command *command,
										t_builtin *builtin, t_shell *shell);
char						**eval_genargv(t_command *command);
int							expand_command(t_shell *shell, t_command *cmd);

int							eval_process_heredoc(t_redirection *redirection,
										t_process *process, t_shell *shell);
int							eval_builtin_heredoc(t_redirection *redirection,
										t_builtin *builtin, t_shell *shell);
char						*eval_getbin(const char *name, t_shell *shell);

int							print_error(const char *path, const char *msg);
int							error_access(const char *path, int right);

int							setvar_shell(t_shell *shell);
int							setvar_user(t_shell *shell);
int							setvar_home(t_shell *shell);
int							setvar_shlvl(t_shell *shell);
int							setvar_path(t_shell *shell);
int							setvar_pwd(t_shell *shell);
#endif
