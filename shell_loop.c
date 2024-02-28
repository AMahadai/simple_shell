#include "shell.h"

/**
 * shell_loop - Main loop for the shell
 * @env: The environment variables
 */
void shell_loop(char **env)
{
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_line();
        args = split_line(line);
        status = execute(args, env);
        free(line);
        free(args);
    } while (status);
}
