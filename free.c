#include "header.h"
/**
 * multiFree - frees n number of pointers
 * @n: the number of pointers to free
 * Return: void
 * @...: the pointers to free
 * Description: frees n number of pointers
 */
void multiFree(int n, ...)
{
va_list valist;
int i;
va_start(valist, n);
for (i = 0; i < n; i++)
{
free(va_arg(valist, void *));
}
va_end(valist);
}
