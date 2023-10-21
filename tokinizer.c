#include "header.h"
/**
 * tokinizer - Splits a string into tokens using a delimiter
 * and returns a pointer to the first token.
 * The original string is modified in the process.
 * @command: The string to tokenize.
 * @delim: The delimiter to use for tokenization.
 * @path_copy: A copy of the PATH environment variable.
 * Return: A pointer to the first token in the string.
 */
char *tokinizer(char *command, char *delim, char *path_copy)
{
char *token = NULL;
char *cmdPath = NULL;
struct stat st;
token = strtok(path_copy, delim);
while (token)
{
cmdPath = cmdPathCat(token, command);
if (stat(cmdPath, &st) == 0)
{
free(path_copy);
return (cmdPath);
}
else
token = strtok(NULL, delim);
free(cmdPath);
}
return (NULL);
}
