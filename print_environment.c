#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * print_environment - prints the environment
 *Return: nothing
 */

void print_environment(void)
{
	char **env_var = environ;

	while (*env_var)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}
