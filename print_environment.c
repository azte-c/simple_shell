#include <stdio.h>

/**
 * print_environment - prints the environment
 *Return: nothing
 */

void print_environment(void)
{
	char **environment = environment;

	while (*environment)
	{
		printf("%s\n", *environment);
		environment++;
	}
}
