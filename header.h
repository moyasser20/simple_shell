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
#include <stdarg.h>   /*va_list*/
/*Prototypes*/
/*Path*/
char *_getCommandPath(char *command);
char *cmdPathCat(char *token, char *command);

/* string functions */
int strcmp1(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *strdup_(const char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);


/*errors*/
int getline_error(int cmd_len);
int strdup_error(char *cmd_copy);
int mallocerror(char **argv);
int forkError(void);
void *checkNullCommand(char *cmd);
void *checkNullPath(char *path);
/*get argc and argv*/
int getargc(char *cmd, char *delim);
char **getargv(int argc, char *cmd_copy, char *delim);
/*free*/
void multiFree(int n, ...);
/*exit case*/
void exitCase(char *cmd_copy, char **argv, char *cmdPath, char *cmdPath_copy, char *cmd);
/*env case*/
void envCase(char *envp[], char *cmd_copy, char **argv, char *cmdPath, char *cmdPath_copy);
/*chdir case*/
void chdirCase(char **argv, char *cmd_copy, char *cmdPath, char *cmdPath_copy);
/*child process*/
void childProcess(char **argv, char *cmd, int argc, char *cmd_copy);
/*struct for intializing variables*/
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
#endif
