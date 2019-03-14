#ifndef EVAL_H
# define EVAL_H

# include "libft.h"
# include "process.h"
# include "shell.h"

typedef struct s_shell t_shell;

int			eval_line(t_shell *shell);

char		**eval_genargv(t_command *command);

char		*eval_getbin(const char *name, t_shell *shell);
#endif
