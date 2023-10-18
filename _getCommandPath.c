#include "header.h"
/*Function to return the path*/
/**
 * _getCommandPath - Finds the full path of a given command.
 *
 * @command: The command to search for.
 *
 * Return: A pointer to a string containing the full path of the command,
 * or NULL if the command is not found.
 */
char *_getCommandPath(char *command)
{
    char *path = NULL;
    char *path_copy = NULL;
    char *token = NULL;
    char *delim = ":";
    char *cmdPath = NULL;
    struct stat st;
    if (command == NULL)
    {
        free(command);
        return (NULL);
    }
    if (command)
    {
        path = getenv("PATH");
        checkNullPath(path);
        path_copy = strdup(path);
        checkNullPath(path_copy);
        if (path)
        {
            if (command[0] == '/')
            {
                multiFree(1, path_copy);
                return (command);
            }
            else if (command[0] == '.' && command[1] == '/')
            {
                free(path_copy);
                return (command);
            }
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
            multiFree(2, command, path_copy);
            return (NULL);
        }
    }
    return (NULL);
}
