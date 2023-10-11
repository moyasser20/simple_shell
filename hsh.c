#include "header.h"

/**
 * main - prints prompt and waits for user to enter command
 * Return: 0 on success, -1 on failure
 * Description: prints prompt and waits for user to enter command
 * then executes command
 */

int main(void)
{

    int count = 1;
    for (; count > 0; count++)
    {
        pid_t pid = 0;
        int status = 2;
        char *cmd = NULL;
        char *cmdPath = NULL;
        char binPath[] = "/usr/bin/";
        char *argVec[] = {NULL};
        char *envVec[] = {""};
        char *cmd_copy = NULL;
        char *token = NULL;
        char *delim = " \n";
        int argc = 0;
        char **argv = NULL;
        size_t n = 0;
        int i = 0;
        char *cmdPath_copy = NULL;
        int cmd_len = 0;
        int comp = 10;

        // print prompt
        printf("#cisfun$ ");
        // printf("Flag Test: before getline()\n"); //////////////////////////////////////////////

        // get command from user
        cmd_len = getline(&cmd, &n, stdin);
        // check if getline failed
        if (cmd_len == -1)
        {
            perror("getline");
            return (-1);
        }
        // check if getline failed
        if (cmd_len > 1)
        {
            // printf("Flag Test: after cmd\n"); //////////////////////////////////////////////

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
            argv = malloc(sizeof(char *) * (argc + 1));
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
                token = strtok(NULL, delim);
                i++;
            }
            // set last element of argv to NULL
            argv[i] = NULL;
            // printf("Flag Test: after argv\n"); //////////////////////////////////////////////

            // compare argv[0] to exit
            comp = strcmp(argv[0], "exit");
            // printf("comp = %d\n", comp);       //////////////////////////////////////////////
            // printf("argv[0] = %s\n", argv[0]); //////////////////////////////////////////////
            if (comp == 0)
            {
                exit(0);
                // printf("Flag test: performed exit"); //////////////////////////////////////////////
                //  free memory
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);
            }
            else if (comp != 0)
            {
                // fork process
                    // printf("Flag Test: before fork\n"); //////////////////////////////////////////////

                pid = fork();

                if (pid == 0)
                {
                    // allocate memory for cmdPath
                    // printf("Flag Test: child process\n"); //////////////////////////////////////////////
                    cmdPath = malloc(sizeof(char) * (strlen(binPath) + strlen(argv[0]) + 1));
                    // check if malloc failed
                    if (cmdPath == NULL)
                    {
                        perror("malloc");
                        return (-1);
                    }
                    // get path of command
                    cmdPath = _getpath(binPath, argv);
                    // printf("Flag Test: after getting path\n"); //////////////////////////////////////////////

                    // duplicate cmdPath
                    cmdPath_copy = strdup(cmdPath);
                    // check if cmdPath_copy is NULL
                    if (cmdPath_copy == NULL)
                    {
                        perror("strdup");
                        return (-1);
                    }
                    // copy argv into argVec
                    for (i = 0; i < argc; i++)
                    {
                        argVec[i] = argv[i];
                    }
                    // set last element of argVec to NULL
                    argVec[i] = NULL;
                    // printf("Flag Test: before execve\n"); //////////////////////////////////////////////

                    // execute command
                    if (execve(cmdPath_copy, argVec, envVec) == -1)
                    {
                        if (argVec[0] != "NULL")
                        {
                            perror("execve");
                            // printf("Bad Command\n");
                        }
                        exit(0);
                    }

                    // printf("Flag Test: after execve\n"); //////////////////////////////////////////////
                }

                // parent process
                else if (pid > 0)
                {
                    // printf("Flag Test: just started parent\n"); //////////////////////////////////////////////

                    // wait for child process to terminate
                    wait(NULL);
                    //   printf("Flag Test: back to parent process\n"); //////////////////////////////////////////////
                }
                // check if fork failed
                else
                {
                    perror("fork");
                    exit(1);
                }
                // free memory
                free(cmd_copy);
                free(argv);
                free(cmdPath);
                free(cmdPath_copy);


                // printf("Flag Test: memory free is ok\n"); //////////////////////////////////////////////
            }
        }
    }
    return (0);
}