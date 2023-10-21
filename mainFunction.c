#include "header.h"

/**
 * mainFunction - This function is the main
 * function of the simple shell program.
 * It takes in the following parameters:
 * @v: A struct containing variables used
 * throughout the program.
 * @argc: An integer representing the number
 * of arguments passed to the program.
 * @argv: An array of strings representing
 * the arguments passed to the program.
 * @envp: An array of strings representing the environment variables.
 * Return: This function does not return anything.
 */
void mainFunction(vars v, int argc, char **argv, char *envp[])
{
v.cmd_copy = strdup_(v.cmd);
strdup_error(v.cmd_copy);
argc = getargc(v.cmd, v.delim);
argv = getargv(argc, v.cmd_copy, v.delim);
if (strcmp1(argv[0], "exit") == 0)
exitCase(v.cmd_copy, argv, v.cmdPath, v.cmdPath_copy, v.cmd);
else if (strcmp1(argv[0], "env") == 0)
envCase(envp, v.cmd_copy, argv, v.cmdPath, v.cmdPath_copy);
else if (strcmp1(argv[0], "cd") == 0)
chdirCase(argv, v.cmd_copy, v.cmdPath, v.cmdPath_copy);
else
{
v.pid = fork();
if (v.pid == 0)
childProcess(argv, v.cmd, argc, v.cmd_copy);
else if (v.pid > 0)
wait(NULL);
else
forkError();
}
multiFree(3, v.cmd_copy, argv, v.cmdPath_copy);
free(v.cmd);
}
