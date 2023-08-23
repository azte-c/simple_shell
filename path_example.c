#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct PathNode
{
	char *path;
	struct PathNode *next;
} PathNode;


int get_path(char **argsv, int args_count)
{

int get_path( char **args, char )
{
	/*below we can use arg_vectors*/
	const char *commands[] = {"pwd", "ls"};
	/*the getenve function */

	char *path  = getenv("PATH");
	pid_t child_pid;
	char *path_copy = strdup(path);
	char *path_tokens = strtok(path_copy, ":");
	int i;
	PathNode *head = NULL;
	PathNode *current;
	/*the problem with the new line might be here*/
	while (path_tokens != NULL)
	{
		PathNode *new_node = malloc(sizeof(PathNode));
		new_node->path = path_tokens;
		new_node->next = head;
		head = new_node;

		path_tokens = strtok(NULL, ":");
	}

	/*search for executable in each path */

	for (i = 0; i < args_count; i++)
	{
		current = head;

		while (current != NULL)
		{
			char full_path[300];
			snprintf(full_path, sizeof(full_path), "%s/%s", current->path, argsv[i]);
			
			if (access(full_path, X_OK) == 0)
			{
				child_pid = fork();
				if (child_pid == 0)
				{
				execl(full_path, argsv[i], NULL);
				perror("exec");
				exit(-1);
				}
				else if (child_pid == -1)
				{
					perror("fork");
					exit(-1);
				}
				
				printf("found executable: %s \n", full_path);
				break;
			}
			else
				printf("Executable: %s not found \n", full_path);

			current = current->next;
		}
	}
	/*free linked list memory*/
	current = head;

	while (current != NULL)	
	{
		PathNode *temp = current;
		current = current->next;
		free(temp);
	}
	free(path_copy);

	return (0);
}
