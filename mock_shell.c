#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50


/*this handles simple shell 0.1 */
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

        // Fork and execute the command
        pid_t pid = fork();
        if (pid == 0) { // Child process
            execvp(args[0], args);
            perror("Execution failed");
            exit(EXIT_FAILURE);
        } else if (pid > 0) { // Parent process
            wait(NULL); // Wait for the child to finish
        } else { // Fork failed
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

