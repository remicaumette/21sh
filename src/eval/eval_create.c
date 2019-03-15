#include "eval.h"

t_eval		*eval_create(t_process *process)
{
	t_eval		*out;

	if (!(out = ft_memalloc(sizeof(t_eval))))
		return (NULL);
	out->process = process;
	out->next = NULL;
	return (out);
}
