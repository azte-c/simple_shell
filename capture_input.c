#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

/**
 *capture_input - prompts the user and captures the input
 *@prompt_user: stores the prompt to be displayed to the user
 *@user_input: stores the user's input(command)
 *@input_bytes: store the number of bytes from the user's input
 */

void capture_input(char **prompt_user, char **user_input, ssize_t *input_bytes)
{
	*prompt_user = (char *)malloc(sizeof(char) * 2);
	(*prompt_user)[0] = '#';
	(*prompt_user)[1] = '\0';
/*what happens here if the file is not opened correctly ? what will be outputed?*/
/*here we write out the contents of the prompt user */
/*what is the return value of te write function */
	write(STDOUT_FILENO, *prompt_user, 1);
/*here we dynamically allocate memory for this variable to hold whatever the user inputs in the prompt */
	*user_input = (char *)malloc(sizeof(char) * 256);

	if (*user_input == NULL)
	{
		perror("malloc");
		exit(-1);
	}
/*this function  read captures user input from the standard input into memory pointed to by *user input */
/*the number of bytes read is stored into the input_bytes variable */
	*input_bytes = read(STDIN_FILENO, *user_input, 256);
/*this just shows that the user pressed enter without keyeing in anything */
	if (*input_bytes == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
/*this shows there was an error while reading input*/
	else if (*input_bytes == -1)
	{
		perror("read");
		exit(-1);
	}
	(*user_input)[*input_bytes - 1] = '\0';
}
