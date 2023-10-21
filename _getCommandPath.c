#include "header.h"
/*Function to return the path*/
/**
 * _getCommandPath - Finds the full path of a given command.
 * @command: The command to search for.
 * Return: A pointer to a string containing the full path of the command,
 * or NULL if the command is not found.
 */
char *_getCommandPath(char *command)
{
char *path = NULL;
char *path_copy = NULL;
char *delim = ":";
char *cmdPath = NULL;
if (command == NULL)
{
free(command);
return (NULL);
}
if (command)
{
path = getenv("PATH");
if (path == NULL)
{
multiFree(2, path, command);
return (NULL);
}
if (path)
{
if ((command[0] == '/') || (command[0] == '.' && command[1] == '/'))
{
return (command);
multiFree(2, path, command);
}
path_copy = strdup_(path);
cmdPath = tokinizer(command, delim, path_copy);
if (cmdPath == NULL)
{
multiFree(2, path_copy, command);
return (NULL);
}
else
{
return (cmdPath);
multiFree(3, path, path_copy, command);
}
}
}
return (NULL);
}
