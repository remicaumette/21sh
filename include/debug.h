#ifndef DEBUG_H
# define DEBUG_H

#include <stdio.h>

int		g_fd_debug;

# define DEBUG_INIT(x) \
	unlink(x);\
	if ((g_fd_debug = open(x, O_CREAT | O_RDWR | O_APPEND, S_IRWXU | S_IRWXO)) == -1) \
		perror("FAIL to open x"); \


# define DEBUG_FD(x) \
	static int	fd_debug = -1; \
	if (fd_debug == -1) \
	{ \
		unlink(x); \
		if ((fd_debug = open(x, O_CREAT | O_RDWR | O_APPEND, S_IRWXU | S_IRWXO)) == -1) \
			perror("Fail to open x"); \
	}


#endif
