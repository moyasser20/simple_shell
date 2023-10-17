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


