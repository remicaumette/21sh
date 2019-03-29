/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:49:53 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:23:32 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include "libft.h"
# include "parser.h"
# include "process.h"
# include "shell.h"

typedef struct s_builtin	t_builtin;
typedef struct s_shell		t_shell;

t_eval					*eval_create(t_builtin *builtin, t_process *process);
void					eval_destroy(t_eval **eval);

int						run_eval(t_eval *eval, t_shell *shell);
int						eval_all(t_shell *shell);
int						eval_line(t_node *curr, t_shell *shell);
int						eval_command(t_node *node,
										t_eval **eval, t_shell *shell);
int						eval_redirection(t_command *command,
										t_process *process, t_shell *shell);
char					**eval_genargv(t_command *command);

int						eval_heredoc(t_redirection *redirection,
										t_process *process, t_shell *shell);
char					*eval_getbin(const char *name, t_shell *shell);
#endif
