#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	/*getenv retrives the value of an environment variable*/
	char *command = "pwd";
	char *path = getenv("PATH");
	char *copy_path = strdup(path);

	if (path)
	{
		char *token = strok(copy_path, ":");
		while (token != NULL)
		{
			char *command_path = malloc(strlen(token) + strlen(command) + 2);
			if (command_path)
			{
				sprintf(command_path, "%s/%s", token, command);
				/*access is 
				if (access(	

