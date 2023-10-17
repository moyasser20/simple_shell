#include "header.h"

/**
 * getline_error - Calculates the error code for getline() function
 * @cmd_len: The length of the command string
 *
 * Return: The error code for getline() function
 */
int getline_error(int cmd_len)
{
    if (cmd_len == -1)
    {
        perror("getline");
        return (-1);
    }
}
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
}
