#include "shell.h"
/**
 * main - prints prompt and waits for user to enter command
 * Return: 0 on success, -1 on failure
 * Description: prints prompt and waits for user to enter command
 * then executes command
 */

int main(void)
{
    pid_t pid;
    int status = 2;
    char *cmd = NULL;
    char *cmdPath = NULL;
    char binPath[] = "/usr/bin/";
    char *argVec[] = {NULL};
    char *envVec[] = {""};
    char *cmd_copy;
    char *token = NULL;
    char *delim = " \n";
    int argc = 0;
    char **argv = NULL;
    size_t n = 0;
    int i = 0;

    // print prompt
    printf("#cisfun$ ");
    // get command from user
    if (getline(&cmd, &n, stdin) == -1)
    {
        perror("getline");
        return (-1);
    }
    // duplicate cmd
    cmd_copy = strdup(cmd);
    // check if cmd_copy is NULL
    if (cmd_copy == NULL)
    {
        perror("strdup");
        return (-1);
    }
    // tokenize cmd
    token = strtok(cmd, delim);
    // count number of tokens in cmd
    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }
    // allocate memory for argv
    argv = malloc(sizeof(char *) * argc);
    // check if malloc failed
    if (argv == NULL)
    {
        perror("malloc");
        return (-1);
    }
    // tokenize cmd_copy
    token = strtok(cmd_copy, delim);
    // store tokens in argv
    while (token)
    {
        argv[i] = token;
        if (token == "exit")
            return (0);
        token = strtok(NULL, delim);
        i++;
    }
    // set last element of argv to NULL
    argv[i] = NULL;
    // fork process
    pid = fork();
    if (pid == 0 && argc > 0)
    {
        // allocate memory for cmdPath
        cmdPath = malloc(sizeof(char) * (strlen(binPath) + strlen(argv[0]) + 1));
        // check if malloc failed
        if (cmdPath == NULL)
        {
            perror("malloc");
            return (-1);
        }
        // allocate memory for cmdPath
        cmdPath = malloc(sizeof(char) * (strlen(binPath) + strlen(argv[0]) + 1));
        // check if malloc failed
        if (cmdPath == NULL)
        {
            perror("malloc");
            return (-1);
        }
        // concatenate binPath and argv[0]
        cmdPath = strcat(binPath, argv[0]);
        // duplicate cmdPath
        char *cmdPath_copy = strdup(cmdPath);
        // copy argv into argVec
        for (i = 0; i < argc; i++)
        {
            argVec[i] = argv[i];
        }
        // set last element of argVec to NULL
        argVec[i] = NULL;
        // execute command
        if (execve(cmdPath_copy, argVec, envVec) == -1)
        {
            if (argVec[0] != "NULL")
                printf("No such file or directory\n");
        }
    }
    // check if fork failed
    else if (pid == -1)
    {
        perror("fork");
        return (-1);
    }
    // parent process
    else
    {
        // wait for child process to terminate
        wait(&status);
        // free memory
        free(cmd);
        free(cmd_copy);
        free(argv);
        free(cmdPath);
        // exit
        return (0);
    }
    return (0);
}