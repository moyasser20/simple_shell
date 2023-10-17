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
#include <fcntl.h>    /*open*/
#include <errno.h>    /*errno*/
#include <limits.h>   /*PATH_MAX*/

/*Prototypes*/
char *_getCommandPath(char *command);

/* sstringfunction1 */
int strlen1(char *s);
int strcmp1(char *s1, char *s2);

/* sstringfunction2 */

char *_strcpy(char *dest, char *src);
char *strdup_(const char *str);
/* sstringfunction3 */
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src, int n);

/*errors*/
int getline_error(int cmd_len);
int strdup_error(char *cmd_copy);
int mallocerror(char **argv);


/*get argc and argv*/
int getargc(char *cmd, char *delim);
char **getargv(int argc, char *cmd_copy, char *delim);


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
