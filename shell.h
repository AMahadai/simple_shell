#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>  /* Standard input/output definitions */
#include <stdlib.h> /* Standard library for memory allocation, process control, etc. */
#include <unistd.h> /* UNIX standard function definitions */
#include <sys/types.h> /* Definitions of data types used in system calls */
#include <sys/wait.h> /* Declarations for waiting for process termination */
#include <signal.h> /* Signal handling functions */

/* Macros */
#define READ_BUF_SIZE 1024  /* Buffer size for reading input lines */
#define WRITE_BUF_SIZE 1024 /* Buffer size for output */
#define BUF_FLUSH -1        /* Macro to indicate buffer should be flushed */

/**
 * shell_loop - Main loop of the shell that handles input and execution.
 */
void shell_loop(void);

/**
 * read_line - Reads a line from standard input.
 * Return: Dynamically allocated string with the input line.
 */
char *read_line(void);

/**
 * tokenize_line - Tokenizes a line into commands and arguments.
 * @line: The line to tokenize.
 * Return: Array of tokens (strings) derived from the line.
 */
char **tokenize_line(char *line);

/**
 * execute_command - Executes a command based on parsed input.
 * @args: Array of strings representing the command and its arguments.
 * Return: Status code of command execution.
 */
int execute_command(char **args);

/**
 * print_prompt - Prints the shell prompt to standard output.
 */
void print_prompt(void);

/**
 * _strlen - Calculates the length of a string.
 * @str: The string to measure.
 * Return: Length of the string.
 */
int _strlen(char *str);

/**
 * _puts - Outputs a string to standard output.
 * @str: The string to output.
 */
void _puts(char *str);

/**
 * _putchar - Outputs a character to standard output.
 * @c: The character to output.
 */
void _putchar(char c);

#endif
