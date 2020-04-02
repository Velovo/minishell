#include "../head/minishell.h"

void sighandler(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	print_new_line();
}