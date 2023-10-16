#include "header.h"

/**
* _strncpy - Function that copy string to another like strncpy
*
* @dest: Pointer to destination input
* @src : Pointer to source input
* @n : the number bytes from characters @src
*
* Return: @dest
*
*/

char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}

while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}

/**
* _strcat - Function that concatenates two string
*
* @dest: Pointer to destination qinput
* @src : Pointer to source input
* @n : the number bytes from characters @src
*
* Return: @dest
*
*/

char *_strcat(char *dest, char *src, int n)
{
int c, i;

c = 0;
while (dest[c])
{
c++;
}
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[c + i] = src[i];
}
dest[c + i] = '\0';

return (dest);

}

/**
 * _strchr - bbe
 * @s: ff
 * @c: gg
 * Return: Always 0
*/

char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
if (c == '\0')
{
return (s);
}
return (NULL);
}

