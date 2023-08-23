#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50


/*this handles the simple shell 0.2*/
/*deals with the PATH*/
int main() {
    char input[100];
    char *args[MAX_ARGS + 1]; // +1 for the NULL pointer

    while (1) {
        printf("MyShell> ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // Remove the newline character

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int arg_count = 0;
        args[arg_count] = strtok(input, " "); // Tokenize input
        while (args[arg_count] != NULL && arg_count < MAX_ARGS) {
            arg_count++;
            args[arg_count] = strtok(NULL, " "); // Continue tokenizing
        }
        args[arg_count] = NULL; // Mark the end of the array with NULL

        // Search for the command in PATH and execute if found
        char *path = getenv("PATH");
        char *path_copy = strdup(path);
        char *dir = strtok(path_copy, ":");
        while (dir != NULL) {
            char cmd_path[MAX_ARG_LENGTH];
            snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, args[0]);

            if (access(cmd_path, X_OK) == 0) {
                pid_t pid = fork();
                if (pid == 0) { // Child process
                    execv(cmd_path, args);
                    perror("Execution failed");
                    exit(EXIT_FAILURE);
                } else if (pid > 0) { // Parent process
                    wait(NULL); // Wait for the child to finish
                    break; // Stop searching other directories
                } else { // Fork failed
                    perror("Fork failed");
                    exit(EXIT_FAILURE);
                }
            }

            dir = strtok(NULL, ":");
        }

        free(path_copy);

        if (dir == NULL) {
            printf("Command not found: %s\n", args[0]);
        }
    }

    return 0;
}

