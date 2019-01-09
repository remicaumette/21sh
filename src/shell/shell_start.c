/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_start.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:15:02 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 15:50:25 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static const char *type[] = {
	"T_WORD",
	"T_NEWLINE",
	"T_PIPE",
	"T_ANDIF",
	"T_ORIF",
	"T_DSEMI",
	"T_DLESS",
	"T_DGREAT",
	"T_LESSAND",
	"T_GREATAND",
	"T_LESSGREAT",
	"T_DLESSDASH",
	"T_CLOBBER",
};

void		print_token(t_token *token)
{
	printf("token->type: %s\n", type[token->type]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n\n", token->next);
	if (token->next)
		print_token(token->next);
}

void		print_node(t_node *node)
{
	printf("node->type: %s\n", type[node->type]);
	printf("node->command: %p\n", node->command);
	if (node->command)
	{
		printf("node->command->name: %s\n", node->command->name);
		printf("node->command->arguments: %p\n", node->command->arguments);
		for (int i = 0; node->command->arguments && node->command->arguments[i]; i++)
			printf("  - %s\n", node->command->arguments[i]);
		printf("node->command->redirection: %p\n", node->command->redirection);

	}
	printf("node->next: %p\n\n", node->next);
	if (node->next)
		print_node(node->next);
}

int			shell_start(t_shell *shell)
{
	struct termios	term;

	if (tgetent(NULL, shell_getenv(shell, "TERM")) == -1 ||
		tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (1);
	return (shell_readline(shell));
}

int			shell_readline(t_shell *shell)
{
	int		readed;
	char	buf[3];

	(void)shell;
	while ((readed = read(0, buf, 3)) > 0)
	{
		if (buf[0] == 4 && buf[1] == 0 && buf[2] == 0)
			break ;
		
		//	tputs(tgoto(tgetstr("cm", NULL), 5, 5), 1, putchar);
		//tputs(tgetstr(Co))
		write(1, buf, readed);
		//printf("%d %d %d\n", buf[0], buf[1], buf[2]);
	}
	return (0);
}

// while (1)
// 	{
// 		if (get_next_line(0, &line) <= 0)
// 			break ;
// 		if (lexer_tokenize(shell->lexer, line))
// 			return (1);
// 		if ((open = lexer_getmissingtoken(shell->lexer)) != -1)
// 		{
// 			printf("required: %c\n", open);
// 			continue ;
// 		}
// 		if (shell->lexer->begin)
// 		{
// 			printf("=== TOKEN\n");
// 			print_token(shell->lexer->begin);
// 			printf("=== PARSER\n");
// 			printf("parser_parse = %d\n", parser_parse(shell->parser));
// 			print_node(shell->parser->root);
// 		}
// 		ft_strdel(&line);
// 		lexer_cleanup(shell->lexer);
// 		parser_cleanup(shell->parser);
// 	}
