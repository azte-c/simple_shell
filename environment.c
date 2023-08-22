#include "shell.h"

void _environment(void);

/**
 * getenv - gets the environment variables
 * @env_variable: it is an environment variable
 * Return: contents of the variable
 */


char *getenv(char *env_variable)
{
	int x, y;
	int status;
	x = 0;

	while (environ[x])
	{
		status = 1;
		for (y = 0; environ[x][y] != '='; j++)
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
		printf("%s\n", environ[x]);
		x++;
	}
}
