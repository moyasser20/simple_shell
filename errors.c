#include "header.h"

/**
 * strdup_error - Calculates the error code for strdup() function
 * @cmd_copy: A copy of the command string
 *
 * Return: The error code for strdup() function
 */
int strdup_error(char *cmd_copy)
{
if (cmd_copy == NULL)
{
perror("strdup");
return (-1);
}
return (0);
}
/**
 * mallocerror - Calculates the error code for malloc() function
 * @argv: An array of strings containing the arguments passed to the program
 *
 * Return: The error code for malloc() function
 */
int mallocerror(char **argv)
{
if (argv == NULL)
{
perror("malloc");
return (-1);
}
return (0);
}

/**
 * forkError - Prints an error message when a fork fails
 *
 * Return: Always returns -1
 */
int forkError(void)
{
perror("fork");
return (-1);
}
