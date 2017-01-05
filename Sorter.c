#include "Sorter.h"
#include  <stdlib.h>

static int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void Sorter_sort(long int * items, long int length)
{
    qsort(items, length, sizeof(long int), cmpfunc);
}

