#include "header.h"
void childProcess(char **argv, char *cmd, int argc, char *cmd_copy)
{
    char *argVec[] = {NULL};
    char *envVec[] = {""};
    char *cmdPath = NULL;
    char *cmdPath_copy = NULL;
    int i;

    cmdPath = _getCommandPath(argv[0]);
    if (cmdPath == NULL)
    {
        perror("cmdPath");
        multiFree(2, argv, cmd);
        exit(0);
    }
    cmdPath_copy = strdup_(cmdPath);
    if (cmdPath_copy == NULL)
    {
        perror("strdup");
        exit(0);
    }
    for (i = 0; i < argc; i++)
    {
        argVec[i] = argv[i];
    }
    argVec[i] = NULL;
    if (execve(cmdPath_copy, argVec, envVec) == -1)
    {
        if ((strcmp(argv[0], "NULL")) == 0)
        {
            perror("argv");
            multiFree(4, cmd_copy, argv, cmd, cmdPath_copy);
        }
        exit(0);

    }
}
