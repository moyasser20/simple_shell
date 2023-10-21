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
#include <stdarg.h>   /*va_list*/

/*struct for intializing variables*/
/**
 * struct variables - struct for intializing variables
 * @pid: process id
 * @n: size_t
 * @i: int
 * @cmd_len: length of command
 * @cmd: command
 * @cmdPath: path of command
 * @cmd_copy: copy of command
 * @token: token
 * @cmdPath_copy: copy of path of command
 * @delim: delimiter
 * Description: struct for intializing variables
 * Return: struct
 */
typedef struct variables
{
pid_t pid;
size_t n;
int i;
int cmd_len;
char *cmd;
char *cmdPath;
char *cmd_copy;
char *token;
char *cmdPath_copy;
char *delim;
} vars;
#define INIT_VARS {0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, " \n"}

/*Prototypes*/
void mainFunction(vars v, int argc, char **argv, char *envp[]);

/*Path*/
char *_getCommandPath(char *command);
char *cmdPathCat(char *token, char *command);

/* string functions */
int strcmp1(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *strdup_(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);


/*errors*/
int strdup_error(char *cmd_copy);
int mallocerror(char **argv);
int forkError(void);
/*get argc and argv*/
int getargc(char *cmd, char *delim);
char **getargv(int argc, char *cmd_copy, char *delim);
/*free*/
void multiFree(int n, ...);
/*exit case*/
void exitCase(char *cmd_copy, char **argv, char *cmdPath
, char *cmdPath_copy, char *cmd);
/*env case*/
void envCase(char *envp[], char *cmd_copy
, char **argv, char *cmdPath, char *cmdPath_copy);
/*chdir case*/
void chdirCase(char **argv, char *cmd_copy
, char *cmdPath, char *cmdPath_copy);
/*child process*/
void childProcess(char **argv, char *cmd, int argc, char *cmd_copy);

char *tokinizer(char *command, char *delim, char *path_copy);



#endif
