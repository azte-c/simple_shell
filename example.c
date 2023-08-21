#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <stdbool.h>
#include <math.h>

/**
 * this rogram is to be used as a blue print for the whole shell project
 * what it does is replicate the functions to a simpler state
 * and i will explain what each segment tries to replicate
 */

int main(void)
{
	/*this while loop enusres that the program runs inf=definetly*/
	while (true)
	{

	char *number = NULL;
	char buffer[200];
	char *command = NULL;
	char *command_copy = NULL;
	char *token = NULL;
	char *delimitor = " \n";
	int arg_count = 0, i = 0;
	char **arg_vector = NULL;
	size_t n = 0;
	ssize_t bytes_written;
	const char *output = "# ";
	char feedback[200];
	
	/*this bit outputs what we want the user to interprate as a promp*/
	write(STDOUT_FILENO, output, 2);

	/*this getline function takes the whole lie of ewhatever the user keyed in*/
	if (getline(&command, &n, stdin) == -1)
		return (-1);
	/*copy the commands so that we manipulate the copy not original commands*/
	command_copy = strdup(command);/*we have to replicate this strdup function*/

	/*this part was to check if the arg_count was working*/
	/*
	while (command[i])
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

	/*this while loop increases the arg_count to match number of tokens(arguments)*/
	while (token)
	{
		token = strtok(NULL, delimitor);
		arg_count++;
	}

	/*this printf is not allowed but i have used it to check if the ehile loop worked*/
	printf("%d\n", arg_count);
        /*i have failed to convert the integer to string to then use write function. segmentation fault*/
	/*      
        snprintf(number, sizeof(number), "%d", arg_count);

        bytes_written = write(STDOUT_FILENO, number, strlen(number));
        if (bytes_written == -1)
        {
                perror("write");
                return (1);
        }
	*/
   	
	/*we have assigned memory dynamically to store the actuall tokens(commands)*/
	arg_vector = malloc(sizeof(char *) * arg_count);
	
	/*tokenizing the commands that we are actually going to use*/
	token = strtok(command_copy, delimitor);

	/*this loop stores the tokens(commands in order in an array so that we can manipulate them*/
	while (token)
	{
		arg_vector[i] = token;
		token = strtok(NULL, delimitor);/*tokenization happens one by one hence this is neede*/
		i++;
	}
	arg_vector[i] = NULL; /*this is common practise to indicate end of array*/


	i = 0;
	/*i used this to show that the tokens have beeb succesfully stored in the array*/
	while (arg_vector[i])
	{
		snprintf(feedback, sizeof(feedback), "%s\n", arg_vector[i]);
		write(STDOUT_FILENO, feedback, strlen(feedback));
		i++;
	}
	
	i = 0;
	/*i used this to show that the tokens can be used*/
	while (arg_vector[i])
	{
		if (strcmp(arg_vector[i], "masi") == 0)
		{
			snprintf(feedback, sizeof(feedback), "%s  is second name\n", arg_vector[i]);
			write(STDOUT_FILENO, feedback, strlen(feedback));
		}
		else if (strcmp(arg_vector[i], "daniel") == 0)
		{
			snprintf(feedback, sizeof(feedback), "%s is first name\n", arg_vector[i]);
			write(STDOUT_FILENO, feedback, strlen(feedback));
		}
		else 
		{
			snprintf(feedback, sizeof(feedback), "%s is not a  name\n", arg_vector[i]);
			write(STDOUT_FILENO, feedback, strlen(feedback));
		}
		i++;
	}

	/*here we then free any memory that was dynamically allocated*/
	free(command);
	free(command_copy);
	free(arg_vector);
	}
	return (0);
}
