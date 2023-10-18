#include "header.h"



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
