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
if (v.cmd_len == EOF)
{
if (isatty(STDIN_FILENO))
printf("\n");
free(v.cmd);
exit(0);
}
if (v.cmd[v.cmd_len - 1] == '\n')
v.cmd[v.cmd_len - 1] = '\0';
if (v.cmd_len == -1)
{
printf("getline error\n");
free(v.cmd);
exit(0);
}
if (v.cmd_len == 1)
{
free(v.cmd);
continue;
}
else if (v.cmd_len > 1)
{
if (v.cmd[0] == ' ')
{
free(v.cmd);
continue;
}
else
{
mainFunction(v, argc, argv, envp);
}
}
}
return (0);
}
