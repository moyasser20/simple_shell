#include "header.h"
/**
 * main -The main function of the simple_shell program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments passed to the program.
 * @envp: An array of strings containing the environment variables.
 * Return: 0 on success, -1 on failure.
 */
int main(int argc, char *argv[], char *envp[])
{
while (1)
{
vars v = INIT_VARS;
if (isatty(STDIN_FILENO))
printf("#cisfun$ ");
v.cmd_len = getline(&v.cmd, &v.n, stdin);
printf("cmd_len: %d\n", v.cmd_len);
if (v.cmd_len == -1)
{
free(v.cmd);
exit(1);
}


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
multiFree(3, v.cmd_copy, argv, v.cmdPath_copy);
}

free(v.cmd);
}
return (0);
}
