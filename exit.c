#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 *exit_shell - exits the shell
 */
void exit_shell(void)
{
	char exit_output[] = "Exiting the shell ... \n";
	write(STDOUT_FILENO, exit_output, sizeof(exit_output) - 1);
	exit(0);
}
