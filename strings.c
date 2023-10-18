#include "header.h"

/**
 * strdup_ - sdfsd
 * @str: asdj
 * Return: dsfadsf
 */
char *strdup_(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
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
