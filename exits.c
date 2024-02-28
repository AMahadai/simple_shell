#include "shell.h"

/**
 * _strncpy - Copy a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of characters to copy.
 *
 * Return: The concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - Concatenate two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to use.
 *
 * Return: The concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - Locate a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area containing the character, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * exit_shell - Exit the shell.
 * @args: Array of arguments passed to the shell.
 * @env: The environment variables.
 *
 * Return: Always returns 0 to indicate successful exit.
 */
int exit_shell(char **args, char **env)
{
	int status = 0;

	(void)env;

	if (args[1])
	{
		status = _atoi(args[1]);
		if (status == -1)
		{
			print_usage_error(args[0], "exit: illegal number:", 2);
			return (2);
		}
	}

	free_env(env);
	free_args(args);
	exit(status);
}
