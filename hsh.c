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
        pid_t pid = 0;
        char *cmd, *cmdPath, *cmd_copy, *token, *cmdPath_copy = NULL;
        char *argVec[] = {NULL};
        char *envVec[] = {""};
        char *delim = " \n";
        size_t n = 0;
        int i = 0;
        int cmd_len = 0;
        argc = 0;
        argv = NULL;

        printf("#cisfun$ ");
        cmd_len = getline(&cmd, &n, stdin);
        if (cmd_len == -1)
        {
            perror("getline");
            return (-1);
        }
        if (cmd_len > 1)
        {
            cmd_copy = strdup_(cmd);
            if (cmd_copy == NULL)
            {
                perror("strdup");
                return (-1);
            }
            token = strtok(cmd, delim);
            while (token)
            {
                token = strtok(NULL, delim);
                argc++;
            }
            argv = malloc(sizeof(char *) * (argc + 1));
            if (argv == NULL)
            {
                perror("malloc");
                return (-1);
            }
            token = strtok(cmd_copy, delim);
            while (token)
            {
                argv[i] = token;
                token = strtok(NULL, delim);
                i++;
            }
            argv[i] = NULL;
            if (strcmp1(argv[0], "exit") == 0)
            {
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
                free(cmd);
                return (0);
            }
            else if (strcmp1(argv[0], "env") == 0)
            {
                for (i = 0; envp[i] != NULL; i++)
                {
                    printf("%s\n", envp[i]);
                }
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
            }
            else if (strcmp1(argv[0], "cd") == 0)
            {
                if (chdir(argv[1]) == -1)
                {
                    perror("chdir");
                }
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
            }
            else
            {
                pid = fork();
                if (pid == 0)
                {
                    cmdPath = _getCommandPath(argv[0]);
                    if (cmdPath == NULL)
                    {
                        perror("cmdPath");
                        free(argv);
                        free(cmd);
                        return (-1);
                    }
                    cmdPath_copy = strdup_(cmdPath);
                    if (cmdPath_copy == NULL)
                    {
                        perror("strdup");
                        return (-1);
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
                            perror("execve");
                            free(cmdPath_copy);
                            free(cmd_copy);
                            free(argv);
                            free(cmd);
                        }
                        return (-1);
                    }
                }
                else if (pid > 0)
                    wait(NULL);
                else
                {
                    perror("fork");
                    return (-1);
                }
                free(cmd_copy);
                free(argv);
                free(cmdPath_copy);
            }
        }
        free(cmd);
    }
    return (0);
}
