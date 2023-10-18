#include "header.h"
/**
 * childProcess - Executes a command in a child process.
 * @argv: An array of strings containing the command and its arguments.
 * @cmd: The command to be executed.
 * @argc: The number of arguments in the `argv` array.
 * @cmd_copy: A copy of the command string.
 * Return: Nothing.
 */
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
argVec[i] = argv[i];
argVec[i] = NULL;
if(1 == 2)
{
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
printf("No such file or directory\n");
}
