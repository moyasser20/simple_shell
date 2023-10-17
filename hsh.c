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
    int count = 1;
    for (; count > 0; count++)
    {
        vars v = INIT_VARS;

        char *argVec[] = {NULL};
        char *envVec[] = {""};

        argv = NULL;

        printf("#cisfun$ ");
        v.cmd_len = getline(&v.cmd, &v.n, stdin);

        getline_error(v.cmd_len);

        if (v.cmd_len > 1)
        {
            v.cmd_copy = strdup_(v.cmd);
            strdup_error(v.cmd_copy);
            argc = getargc(v.cmd, v.delim);
            argv = getargv(argc, v.cmd_copy, v.delim);
            if (strcmp1(argv[0], "exit") == 0)
            {
                free(v.cmd_copy);
                free(argv);
                free(v.cmdPath);
                free(v.cmdPath_copy);
                free(v.cmd);
                return (0);
            }
            else if (strcmp1(argv[0], "env") == 0)
            {
                for (v.i = 0; envp[v.i] != NULL; v.i++)
                {
                    printf("%s\n", envp[v.i]);
                }
                free(v.cmd_copy);
                free(argv);
                free(v.cmdPath);
                free(v.cmdPath_copy);
            }
            else if (strcmp1(argv[0], "cd") == 0)
            {
                if (chdir(argv[1]) == -1)
                {
                    perror("chdir");
                }
                free(v.cmd_copy);
                free(argv);
                free(v.cmdPath);
                free(v.cmdPath_copy);
            }
            else
            {
                v.pid = fork();
                if (v.pid == 0)
                {
                    v.cmdPath = _getCommandPath(argv[0]);
                    if (v.cmdPath == NULL)
                    {
                        perror("cmdPath");
                        free(argv);
                        free(v.cmd);
                        return (-1);
                    }
                    v.cmdPath_copy = strdup_(v.cmdPath);
                    if (v.cmdPath_copy == NULL)
                    {
                        perror("strdup");
                        return (-1);
                    }
                    for (v.i = 0; v.i < argc; v.i++)
                    {
                        argVec[v.i] = argv[v.i];
                    }
                    argVec[v.i] = NULL;
                    if (execve(v.cmdPath_copy, argVec, envVec) == -1)
                    {
                        if ((strcmp(argv[0], "NULL")) == 0)
                        {
                            perror("execve");
                            free(v.cmdPath_copy);
                            free(v.cmd_copy);
                            free(argv);
                            free(v.cmd);
                        }
                        return (-1);
                    }
                }
                else if (v.pid > 0)
                    wait(NULL);
                else
                {
                    perror("fork");
                    return (-1);
                }
                free(v.cmd_copy);
                free(argv);
                free(v.cmdPath_copy);
            }
        }
        free(v.cmd);
    }
    return (0);
}
