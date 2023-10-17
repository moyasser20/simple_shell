#include "header.h"
/**
 * getargc - get argc
 * @cmd: command
 * @delim: delimiter
 * Return: argc
 */
int getargc(char *cmd, char *delim)
{
    int argc = 0;
    char *token = NULL;
    token = strtok(cmd, delim);
    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }
    return (argc);
}
/**
 * getargv - get argv
 * @argc: argument count
 * @cmd_copy: command copy
 * @delim: delimiter
 * Return: argv
 */
char **getargv(int argc, char *cmd_copy, char *delim)
{
    char **argv = NULL;
    int i = 0;
    char *token = NULL;
    argv = malloc(sizeof(char *) * (argc + 1));
    mallocerror(argv);
    token = strtok(cmd_copy, delim);
    while (token)
    {
        argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    argv[i] = NULL;
    return (argv);
}

