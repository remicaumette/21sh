#include "eval.h"

void		eval_destroy(t_eval **eval)
{
	t_eval		*tmp;
	t_eval		*tmp_next;

	tmp = *eval;
	while (tmp)
	{
		process_destroy(&tmp->process);
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	*eval = NULL;
}
