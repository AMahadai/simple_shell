#include "shell.h"
/**
* init_info - Initializes the info_t struct.
* @info: Pointer to the info_t struct to initialize.
*/
void init_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}
/**
* parse_info - Parses and sets information in the info_t struct.
* @info: Pointer to the info_t struct to parse and set.
* @arg: Argument string.
*/
void parse_info(info_t *info, char *arg)
{
int i = 0;
info->fname = info->argv[0];
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;
replace_alias(info);
replace_vars(info);
}
}
/**
* free_info - Frees memory allocated for the info_t struct.
* @info: Pointer to the info_t struct to free.
* @all: Flag indicating whether to free all fields.
*/
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
ffree(info->environ);
info->environ = NULL;
bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}
