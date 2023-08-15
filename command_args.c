#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - is the entry point
 * @arg_count - no of arguments
 * @arg_vector - double pointer to arguments
 * return 0 (success) 1 (error)
 */
void loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("myshell ");
		line =

/*we use arg_count and arg_vector to access the command line arguments*/


int main(int arg_count, char **arg_vector)
{
	/*here we will handle prassing*/
	for (int i = 0; i <arg_count; i++)
	{
		
	}

	/*here we will handle if no argument is provided first*/
	if (arg_count < 2)
	{
		printf("no argument was provided\n");
		return (1);
	}

	if (strcmp(arg_vector, "command") == 0)
	{
		/*call function for command*/
	}
	else if (strcmp(arg_vector, "command1") == 0)
	{
		/*call funtion for command2*/
	}
	else
	{
		/*implement how to handle an unkown command*/
	return (1);
	}

	return (0);
}
