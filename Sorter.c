#include "Sorter.h"

static void quicksort(long int * items, long int left, long int right)
{
    long int wall;

    do {
        wall = partition(items, left, right);
        quicksort(items, left, wall);
        quicksort(items, wall, right);
    }
    while (wall < right);
}

static long int partition(long int * items, long int left, long int right)
{
    long int pivot = items[right];
    long int wall = left;
    long int i;

    for (i = wall; i < right; i++)
    {
        if (items[i] <= pivot)
        {
            swap(items, wall, i);
            wall++;
        }
        i++;
    }

    return wall;
}

static void swap(long int * items, long int left, long int right)
{
    long int temporary = items[left];
    items[left] = items[right];
    items[right] = temporary;
}

void Sorter_sort(long int * items, long int length)
{
    if (1 == length) {
        return;
    }

    long int left = 0;
    long int right = length - 1;
    quicksort(items, left, right);
}
