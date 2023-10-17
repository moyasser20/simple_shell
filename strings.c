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
 * strcmp1 - compare between two strings
 * @s1: first string
 * @s2: second string
 * Return: negative if s1<s2 , postive if s1>s2
 */

int strcmp1(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
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
 * @s: pointer to the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
int i = 0;
while (s[i])
i++;
return (i);
}


