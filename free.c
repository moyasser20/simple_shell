#include "header.h"
// write a function that free multiple variables
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

