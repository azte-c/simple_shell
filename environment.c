#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void _environment(void);
char **environ = NULL;
/**
 * custom_getenv - gets the environment variables
 * @env_variable: it is an environment variable
 * Return: a pointer to character in environ array
 */

char *custom_getenv(char *env_variable)
{
	int x, y;
	int status;

	x = 0;

	while (environ[x])
	{
		status = 1;
		for (y = 0; environ[x][y] != '='; y++)
		{
			if (environ[x][y] != env_variable[y])
				status = 0;
		}
		if (status == 1)
			break;
		x++;
	}
	return (&environ[x][y + 1]);
}


/**
 * _environment - print out the environmrent
 */

void _environment(void)
{
	int x = 0;

	while (environ[x])
	{
		/** replacing printf("%s\n", environ[x]) */
		write(STDOUT_FILENO, environ[x], strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
