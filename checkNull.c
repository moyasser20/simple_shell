#include "header.h"


/**
 * checkNullCommand - Prints an error message when a command is NULL
 * @cmd: The command string
 * Return: Always returns NULL
 */
void *checkNullCommand(char *cmd)
{
if (cmd == NULL)
{
perror("cmd");
return (NULL);
}
return (0);
}

/**
 * checkNullPath - Prints an error message when a path is NULL
 * @path: The path string
 * Return: Always returns NULL
 */
void *checkNullPath(char *path)
{
if (path == NULL)
{
perror("path");
return (NULL);
}
return (0);
}
