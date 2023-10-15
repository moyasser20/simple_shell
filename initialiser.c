#include "header.h"

void initialiser (void)
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
}