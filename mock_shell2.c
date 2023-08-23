#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50

/*deals with simple shell0.4*/
/*deals with the env */
extern char **environ; // Declaration for the environment variable

void print_environment() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

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
        } else if (strcmp(input, "env") == 0) {
            print_environment();
            continue;
        }

        int arg_count = 0;
        args[arg_count] = strtok(input, " "); // Tokenize input
        while (args[arg_count] != NULL && arg_count < MAX_ARGS) {
            arg_count++;
            args[arg_count] = strtok(NULL, " "); // Continue tokenizing
        }
        args[arg_count] = NULL; // Mark the end of the array with NULL

        // Rest of the code for command execution (as in previous examples)
    }

    return 0;
}

