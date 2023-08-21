#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 *get_path - checks the path to be followed into directories
 *Return: 0
 */

int get_path(void)
{
	char *user_input = NULL;
	size_t input_size = 0;
	ssize_t char_read;
	char *path, *check_directory, *command;
	char executable_path[256];

	char_read = get_line(user_input, input_size, &user_input, &input_size);

	if (char_read == -1)
	{
		perror("User input error");
	}
	else
	{
		command = strtok(user_input, " \t\n");
		path = gentenv("PATH");
		check_directory = strtok(path, ":");

		while (check_directory != NULL)
		{
			snprintf(executable_path[executable_path], sizeof(executable_path),
					"%s/%s", check_directory, tokenize_command);
			if (access(executable_path, X_OK) == 0)
			{
				execl(executable_path, command, NULL);
				perror("Access denied");
				break;
			}
			check_directory = strtok(NULL, ":");
		}
		perror("Command not found");
	}
	free(user_input);
}
return (0);
}