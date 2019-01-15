#ifndef DEBUG_H
# define DEBUG_H

#include <stdio.h>

# define DEBUG_FD(x) \
	static int	fd = -1; \
	if (fd == -1) \
	{ \
		unlink(x); \
		if ((fd = open(x, O_CREAT | O_RDWR | O_APPEND, S_IRWXU | S_IRWXO)) == -1) \
			perror("Fail to open x"); \
	}


#endif
