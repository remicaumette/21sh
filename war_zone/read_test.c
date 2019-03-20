#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>

# define BUFF_SIZE 1024

int main(void)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	ret = 0;
	bzero(buf, BUFF_SIZE);
	dprintf(STDOUT_FILENO, "Start read Test\n");
	while ((ret = read(STDIN_FILENO, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		dprintf(STDOUT_FILENO, "ret=%d, line=%s\n", ret, buf);
		if (strncmp(buf, "exit", 4) == 0)
			break ;
	}
	if (ret == -1)
		perror("Fail read");
	dprintf(STDOUT_FILENO, "End read Test\n");
	return 0;
}
