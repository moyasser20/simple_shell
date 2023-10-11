/**
 * @file shell.h
 * @brief Header file for shell.c
 * @details Contains the function prototypes and global variables for shell.c
 */
#ifndef SHELL_H
#define SHELL_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

// Defines

// Prototypes
char *_getpath(char *binPath, char **argv);

// Function to return the path

/**
 * @brief Function to return the path
 * @details This function returns the path of the command to be executed
 * @param binPath The path of the bin directory
 * @param argv The command to be executed
 * @return The path of the command
 */
char *_getpath(char *binPath, char **argv)
{
    char *cmdPath = NULL;

    //allocate memory for cmdPath
    cmdPath = malloc(sizeof(char) * (strlen(binPath) + strlen(argv[0]) + 1));
    // check if malloc failed
    if (cmdPath == NULL)
    {
        perror("malloc");
    }
    // concatenate binPath and argv[0]
    cmdPath = strcat(binPath, argv[0]);
    // add null terminator to cmdPath
    cmdPath[strlen(binPath) + strlen(argv[0])] = '\0';
    return (cmdPath);
    free(cmdPath);
}

// Function to print the prompt

// Function to read the command line

// Function to parse the command line

// Function to execute the command

#endif