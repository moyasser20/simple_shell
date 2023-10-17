#include "header.h"
/*getline error check*/
int getline_error(int cmd_len)
{
    if (cmd_len == -1)
    {
        perror("getline");
        return (-1);
    }
}
/*strdup error check*/
int strdup_error(char *cmd_copy)
{
    if (cmd_copy == NULL)
    {
        perror("strdup");
        return (-1);
    }
}
/*malloc error check*/
int mallocerror(char **argv)
{
    if (argv == NULL)
    {
        perror("malloc");
        return (-1);
    }
}
