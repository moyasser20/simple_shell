#include "header.h"

/**
 * strdup_ - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the new string
 */
char *strdup_(char *str)
{
char *dup;
int i = 0, len = 0;
if (str == NULL)
return (NULL);
while (str[len])
len++;
dup = malloc(sizeof(char) * (len + 1));
if (dup == NULL)
return (NULL);
while (i < len)
{
dup[i] = str[i];
i++;
}
dup[i] = '\0';
return (dup);
free(dup);
}

/**
 * strcmp1 - Compares two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * Return: An integer less than, equal to,
 * or greater than zero if str1 is found,
 * respectively, to be less than, to match, or be greater than str2.
 */
int strcmp1(char *str1, char *str2)
{
int i = 0;
if (!str1 || !str2)
return (-1);
while (str1[i] && str2[i] && str1[i] == str2[i])
i++;
return (str1[i] - str2[i]);
}



/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: pointer to the buffer in which we copy the string
 * @src: pointer to the string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src)
{
int i = 0, j = 0;
while (dest[i])
i++;
while (src[j])
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
