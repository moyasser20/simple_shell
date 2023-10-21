#include "header.h"

/**
 * exitCase - handles the exit command
 * @cmd_copy: a copy of the command entered by the user
 * @argv: an array of arguments passed to the command
 * @cmdPath: the path of the command
 * @cmdPath_copy: a copy of the path of the command
 * @cmd: the command entered by the user
 */
void exitCase(char *cmd_copy, char **argv,
char *cmdPath, char *cmdPath_copy, char *cmd)
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
void envCase(char *envp[], char *cmd_copy, char **argv,
char *cmdPath, char *cmdPath_copy)
{
int i;
for (i = 0; envp[i] != NULL; i++)
{
printf("%s\n", envp[i]);
}
multiFree(4, cmd_copy, argv, cmdPath, cmdPath_copy);
}
/**
 * chdirCase - handles the cd command
 * @argv: an array of arguments passed to the command
 * @cmd_copy: a copy of the command entered by the user
 * @argv: an array of arguments passed to the command
 * @cmdPath: the path of the command
 * @cmdPath_copy: a copy of the path of the command
 * handle cd - change directory
 */
void chdirCase(char **argv, char *cmd_copy, char *cmdPath, char *cmdPath_copy)
{
int i;
if (argv[1] == NULL)
{
chdir(getenv("HOME"));
multiFree(4, cmd_copy, argv, cmdPath, cmdPath_copy);
return;
}
else if (argv[1][0] == '-' && argv[1][1] == '\0')
{
chdir(getenv("OLDPWD"));
printf("%s\n", getenv("OLDPWD"));
multiFree(4, cmd_copy, argv, cmdPath, cmdPath_copy);
return;
}
else
{
i = chdir(argv[1]);
if (i == -1)
{
perror("chdir");
multiFree(4, cmd_copy, argv, cmdPath, cmdPath_copy);
return;
}
}
multiFree(4, cmd_copy, argv, cmdPath, cmdPath_copy);
}
