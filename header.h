/**
 * @file shell.h
 * @brief Header file for shell.c
 * @details Contains the function prototypes and global variables for shell.c
 */
#ifndef SHELL_H
#define SHELL_H

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h> /*stat*/
#include <fcntl.h>/*open*/
#include <errno.h>/*errno*/
#include <limits.h>   /*PATH_MAX*/

/*Prototypes*/
char *_getCommandPath(char *command);
void initialiser (void);


/* sstringfunction1 */
int strlen1(char *s);
int strcmp1(char *s1, char *s2);

/* sstringfunction2 */

char *_strcpy(char *dest, char *src);
char *strdup_(const char *str);
 /* sstringfunction3 */
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src, int n);

/*Function to return the path*/

/**
 * Returns the file path of the given command.
 *
 * @param command The command to get the file path for.
 * @return The file path of the command, or NULL if it could not be found.
 */
char *_getCommandPath(char *command)
{
char *path = NULL;
char *path_copy = NULL;
char *token = NULL;
char *delim = ":";
char *cmdPath = NULL;
struct stat st;

/*check if command is NULL*/
if (command == NULL)
{
perror("command");
return (NULL);
}
/*get path*/
path = getenv("PATH");
/*check if path is NULL*/
if (path == NULL)
{
perror("getenv");
return (NULL);
}
/*copy path*/
path_copy = strdup(path);
/*check if path_copy is NULL*/
if (path_copy == NULL)
{
perror("strdup");
return (NULL);
}

if (path)
{
/*check if command is a path*/
if (command[0] == '/')
{
/*printf("command is a path\n");*/
free(path_copy);
return (command);
}
/*check if command is a relative path*/
else if (command[0] == '.' && command[1] == '/')
{
/*printf("command is a relative path\n");*/
free(path_copy);
return (command);
}
/*tokenize path*/
token = strtok(path_copy, delim);

/*loop through path*/
while (token)
{
/*concatenate token and command*/
cmdPath = malloc(sizeof(char) * (strlen(token) + strlen(command) + 2));
/*check if cmdPath is NULL*/
if (cmdPath == NULL)
{
perror("malloc");
free(cmdPath);
return (NULL);
}
cmdPath = strcpy(cmdPath, token);
cmdPath = strcat(cmdPath, "/");
cmdPath = strcat(cmdPath, command);
cmdPath = strcat(cmdPath, "\0");
/*printf("cmdPath: %s\n", cmdPath);*/
/*check if cmdPath exists*/
if (stat(cmdPath, &st) == 0)
{
/*printf("cmdPath exists\n");*/
/*free path_copy*/
free(path_copy);

return (cmdPath);
}
else
{
token = strtok(NULL, delim);
}
free(cmdPath);
}
free(command);
free(path_copy);

return (NULL);
}
return (NULL);
}

#endif
