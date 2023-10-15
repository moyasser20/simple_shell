#include "header.h"

/**
* strlen1 - return the length of a string
* @s: the string to check the length
* Return: length
*/

int strlen1(char *s)
{
int i = 0;

while (!s)
return (0);

while (*s++)
i++;
return (i);
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
* startswith - checks
* @haystack: ss
* @needle: gf
* Return: address of next char or null
*/

char *startswith(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* *strcat1 - counctination
* @dest: ss
* @src: gg
* Return: pointer or destination buffer
*/
char *strcat1(char *dest, char *src)
{
char *rt = dest;

while (*dest)
dest++;

while (*src)
*dest++ = *src++;

*dest = *src;

return (rt);
}
