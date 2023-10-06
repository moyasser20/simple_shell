#include "shell.h"

/**
 * _strcpy - copy the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 *
 * @dest: char type string
 * @src: char type string
 *
 * Description: copy the string pointed to by pointer src
 * to pointer dest
 *
 * Return: pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
int i = -1;

do {
i++;
dest[i] = src[i];

} while (src[i] != '\0');

return (dest);
}

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
#include "main.h"

/**
* _puts - prints a stirng, followed by a newline to stdout
*
* @str : string parameter to print
*
* Return : Nothing
*/

void _puts(char *str)
{
while (*str != '\0')
{
putchar(*str + 0);
str++;
}
putchar('\n');
}
#include <unistd.h>

/**
 * _putchar - df
 * @c: The character to print
 *
 * Return: On success 1
 * on error, -1 is returned
 *
*/

int _putchar(char c)
{
return (write(1, &c, 1));
}

