#include "parser.h"

int		parser_istoken_redirection(t_tokentype type)
{
	if (type == TOKEN_GREAT || type == TOKEN_DGREAT || type == TOKEN_GREATAND
		|| type == TOKEN_LESS || type == TOKEN_DLESS || type == TOKEN_LESSAND
		|| type == TOKEN_LESSGREAT)
		return (1);
	return (0);
}
