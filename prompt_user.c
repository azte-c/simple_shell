#include "shell.h"

/**
 * prompt_user - handle the prompt user will see
 * Return: NULL
 */

void  prompt_user(void)
{

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "# ", 2);
	}
}
