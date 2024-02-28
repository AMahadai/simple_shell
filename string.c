#include "shell.h"
/**
* _strcmp - Compares two strings lexicographically.
* @s1: The first string to be compared.
* @s2: The second string to be compared.
*
* Return: An integer less than, equal to, or greater than zero if s1 is found,
* respectively, to be less than, to match, or be greater than s2.
*/
int _strcmp(char *s1, char *s2)
{
int i;
for (i = 0; s1[i] && s2[i]; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
return (s1[i] - s2[i]);
}
/**
* _strcpy - Copies the string pointed to by src to dest.
* @dest: The destination buffer.
* @src: The source string to be copied.
*
* Return: A pointer to the destination string dest.
*/
char *_strcpy(char *dest, char *src)
{
int i;
for (i = 0; src[i]; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
/**
* _strdup - Duplicates a string.
* @str: The string to be duplicated.
*
 * Return: A pointer to the newly allocated string, or NULL if malloc fails.
 */
char *_strdup(char *str)
{
char *dup;
int i, len;
len = _strlen(str);
dup = malloc(sizeof(char) * (len + 1));
if (dup == NULL)
return (NULL);
for (i = 0; i <= len; i++)
{
dup[i] = str[i];
}
return (dup);
}
/**
* _strlen - Computes the length of a string.
* @str: The string to be measured.
i*
* Return: The length of the string.
*/
int _strlen(char *str)
{
int len;
for (len = 0; str[len]; len++)
;
return (len);
}
