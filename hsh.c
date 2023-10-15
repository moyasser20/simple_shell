#include "header.h"

/**
 * main -The main function of the simple_shell program.
 *
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
        char *cmd = NULL;
        char *cmdPath = NULL;
        char *argVec[] = {NULL};
        char *envVec[] = {""};
        char *cmd_copy = NULL;
        char *token = NULL;
        char *delim = " \n";
        size_t n = 0;
        int i = 0;
        char *cmdPath_copy = NULL;
        int cmd_len = 0;
        argc = 0;
        argv = NULL;

        /*print prompt*/
        printf("#cisfun$ ");
        /*get command from user*/
        cmd_len = getline(&cmd, &n, stdin);
        /*check if getline failed*/
        if (cmd_len == -1)
        {
            perror("getline");
            return (-1);
        }
        if (cmd_len > 1)
        {
            /*duplicate cmd*/
            cmd_copy = strdup(cmd);
            /*check if cmd_copy is NULL*/
            if (cmd_copy == NULL)
            {
                perror("strdup");
                return (-1);
            }
            /*tokenize cmd*/
            token = strtok(cmd, delim);
            /*count number of tokens in cmd*/
            while (token)
            {
                token = strtok(NULL, delim);
                argc++;
            }
            /*allocate memory for argv*/
            argv = malloc(sizeof(char *) * (argc + 1));
            /*check if malloc failed*/
            if (argv == NULL)
            {
                perror("malloc");
                return (-1);
            }
            /*tokenize cmd_copy*/
            token = strtok(cmd_copy, delim);
            /*store tokens in argv*/
            while (token)
            {
                argv[i] = token;
                token = strtok(NULL, delim);
                i++;
            }
            /*set last element of argv to NULL*/
            argv[i] = NULL;
            if (strcmp(argv[0], "exit") == 0)
            {
                /*free memory*/
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
                free(cmd);
                return (0);
            }
            else if (strcmp(argv[0], "env") == 0)
            {
                /*print environment*/
                for (i = 0; envp[i] != NULL; i++)
                {
                    printf("%s\n", envp[i]);
                }
                /*free memory*/
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
            }
            else if (strcmp(argv[0], "cd") == 0)
            {
                /*change directory*/
                if (chdir(argv[1]) == -1)
                {
                    perror("chdir");
                }
                /*free memory*/
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
            }
            else
            {
                /*fork process*/
                pid = fork();
                if (pid == 0)
                {
                    cmdPath = _getCommandPath(argv[0]);
                    /*check if cmdPath is NULL*/
                    if (cmdPath == NULL)
                    {
                        perror("cmdPath");
                        free(argv);
                        free(cmd);
                        return (-1);
                    }
                    /*duplicate cmdPath*/
                    cmdPath_copy = strdup(cmdPath);
                    /*check if cmdPath_copy is NULL*/
                    if (cmdPath_copy == NULL)
                    {
                        perror("strdup");
                        return (-1);
                    }
                    /*copy argv into argVec*/
                    for (i = 0; i < argc; i++)
                    {
                        argVec[i] = argv[i];
                    }
                    argVec[i] = NULL;
                    /*execute command*/
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
                /*parent process*/
                else if (pid > 0)
                {
                    /*wait for child process to terminate*/
                    wait(NULL);
                }
                /*check if fork failed*/
                else
                {
                    perror("fork");
                    return (-1);
                }
                /*free memory*/
                free(cmd_copy);
                free(argv);
                free(cmdPath_copy);
            }
        }
        free(cmd);
    }
    return (0);
}
