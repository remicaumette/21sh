#include "eval.h"

int		eval_all(t_shell *shell)
{
	t_node		*curr;

	curr = shell->parser->root;
	while (curr)
	{
		if (eval_line(curr, shell) != SUCCESS)
			return (FAIL);
		while (curr && curr->type != TOKEN_NEWLINE)
			curr = curr->next;
		if (curr)
			curr = curr->next;
	}
	return (SUCCESS);
}
