#include "header.h"

/**
 * exitCase - handles the exit command
 * @cmd_copy: a copy of the command entered by the user
 * @argv: an array of arguments passed to the command
 * @cmdPath: the path of the command
 * @cmdPath_copy: a copy of the path of the command
 * @cmd: the command entered by the user
 */
void exitCase(char *cmd_copy, char **argv, char *cmdPath, char *cmdPath_copy, char *cmd)
{
    multiFree(5, cmd_copy, argv, cmdPath, cmdPath_copy, cmd);
    exit(0);
}


/**
 * envCase - handles the env command
 * @envp: an array of environment variables
 * @cmd_copy: a copy of the command entered by the user
 * @argv: an array of arguments passed to the command
 * @cmdPath: the path of the command
 * @cmdPath_copy: a copy of the path of the command
 */
void envCase(char *envp[], char *cmd_copy, char **argv, char *cmdPath, char *cmdPath_copy)
{
    for (int i = 0; envp[i] != NULL; i++)
    {
        printf("%s\n", envp[i]);
    }
    multiFree(4, cmd_copy, argv, cmdPath, cmdPath_copy);
}
