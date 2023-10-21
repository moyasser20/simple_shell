#include "header.h"
/**
 * cmdPathCat - Concatenates the given command
 * with the token to form a full path.
 * @token: The token to concatenate with the command.
 * @command: The command to concatenate with the token.
 * Return: A pointer to the full path string.
 */
char *cmdPathCat(char *token, char *command)
{
char *cmdPath = NULL;

cmdPath = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
if (cmdPath == NULL)
{
perror("malloc");
free(cmdPath);
return (NULL);
}
cmdPath = _strcpy(cmdPath, token);
cmdPath = _strcat(cmdPath, "/");
cmdPath = _strcat(cmdPath, command);
cmdPath = _strcat(cmdPath, "\0");
return (cmdPath);
free(cmdPath);
}
