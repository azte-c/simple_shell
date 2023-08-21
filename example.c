#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**


  */

int main(void)
{
	char *command = NULL;
	char *command_copy = NULL;
	char *token = NULL;
	char *delimitor = " \n";
	int arg_count = 0, i = 0;
	char **arg_vector = NULL;
	size_t n = 0;
	printf("$ ");
	if (getline(&command, &n, stdin) == -1)
		return (-1);
/*this is to copy the commands so that we can manipulate the instead of the original commands*/
	command_copy = strdup(command);

	/*this part was to check if the arg_count was working8/
/*	while (command[i])
	{
		if (command[i] == '\n')
			printf("\\n input has %ld characters ", strlen(command));
		else
			printf("%c", command[i]);
		i++;
	}
*/

	/*this pat tokenizes the arguments passed to the prompt */
	token = strtok(command, delimitor);

	while (token)
	{
		token = strtok(NULL, delimitor);
		arg_count++;
	}
	printf("%d\n", arg_count);

	arg_vector = malloc(sizeof(char *) * arg_count);

	token = strtok(command_copy, delimitor);

	while (token)
	{
		arg_vector[i] = token;
		token = strtok(NULL, delimitor);
		i++;
	}
	arg_vector[i] = NULL;
	printf("%d\n", i);

	i = 0;
	while (arg_vector[i])
		printf("%s\n", arg_vector[i++]);

	free(command);
	free(command_copy);
	free(arg_vector);
	
	return (0);
}
