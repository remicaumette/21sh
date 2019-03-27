/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 15:16:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 15:17:35 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static const char	*g_type[] = {
	"TOKEN_WORD",
	"TOKEN_NEWLINE",
	"TOKEN_PIPE",
	"TOKEN_GREAT",
	"TOKEN_LESS",
	"TOKEN_ANDIF",
	"TOKEN_ORIF",
	"TOKEN_DSEMI",
	"TOKEN_DLESS",
	"TOKEN_DGREAT",
	"TOKEN_LESSAND",
	"TOKEN_GREATAND",
	"TOKEN_LESSGREAT",
	"TOKEN_DLESSDASH",
	"TOKEN_CLOBBER",
	"TOKEN_GREATAND_3",
	"TOKEN_GREATAND_3_TIP",
	"TOKEN_GREATAND_4",
};

void				print_redirection(t_redirection *redirection, int i)
{
	printf("\tredirection num: %d\n", i);
	printf("redirection->type: %s\n", g_type[redirection->type]);
	printf("redirection->file: %s\n", redirection->file);
	printf("redirection->in: %d\n", redirection->in);
	printf("redirection->out: %d\n", redirection->out);
	printf("redirection->next: %p\n", redirection->next);
	if (redirection->next)
		print_redirection(redirection->next, i + 1);
}

void				print_token(t_token *token)
{
	printf("token->type: %s\n", g_type[token->type]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n\n", token->next);
	if (token->next)
		print_token(token->next);
}

void				print_node(t_node *node)
{
	int i;

	i = -1;
	printf("node->type: %s\n", g_type[node->type]);
	printf("node->command: %p\n", node->command);
	if (node->command)
	{
		printf("node->command->name: %s\n", node->command->name);
		printf("node->command->arguments: %p\n", node->command->arguments);
		while (node->command->arguments && node->command->arguments[++i])
			printf("  - %s\n", node->command->arguments[i]);
		printf("node->command->redirection: %p\n", node->command->redirection);
		if (node->command->redirection)
			print_redirection(node->command->redirection, 0);
	}
	printf("node->next: %p\n\n", node->next);
	if (node->next)
		print_node(node->next);
}
