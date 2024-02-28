#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Macros */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Function Prototypes */
void shell_loop(void);
char *read_line(void);
char **tokenize_line(char *line);
int execute_command(char **args);
void print_prompt(void);
int _strlen(char *str);
void _puts(char *str);
void _putchar(char c);

#endif /* SHELL_H */
