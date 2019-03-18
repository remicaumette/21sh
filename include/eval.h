#ifndef EVAL_H
# define EVAL_H

# include "libft.h"
# include "process.h"
# include "shell.h"

typedef struct s_shell	t_shell;
typedef struct s_eval	t_eval;

struct			s_eval
{
	t_process	*process;
	t_eval		*next;
};

t_eval		*eval_create(t_process *process);
void		eval_destroy(t_eval **eval);

int			eval_all(t_shell *shell);
int			eval_line(t_node *curr, t_shell *shell);
int			eval_command(t_node *node, t_eval **eval, t_shell *shell);
int			eval_redirection(t_command *command, t_process *process, t_shell *shell);
char		**eval_genargv(t_command *command);

int			eval_heredoc(t_redirection *redirection, t_process *process, t_shell *shell);
char		*eval_getbin(const char *name, t_shell *shell);
#endif
