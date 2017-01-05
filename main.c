#include "ndb.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 1 || argc > 4)
    {
        return(1);
    }

    if (1 == argc)
    {
        long int nodeId = ndb_create();
        printf("%ld\n", nodeId);
    }

    if (2 == argc)
    {
        long int nodeId = strtol(argv[1], NULL, 10);
        int length = 4096;
        long int buffer[length];
        long int total = ndb_read(nodeId, buffer, length);
        int i = 0;
        while (i < length && i < total)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%ld", buffer[i]);
            i++;
        }
        printf("\n");
    }

    if (3 == argc)
    {
        long int fromNodeId = strtol(argv[1], NULL, 10);
        long int toNodeId = strtol(argv[2], NULL, 10);
        ndb_connect(fromNodeId, toNodeId);
    }

    if (4 == argc)
    {
        int length = 3;
        long int ids[length];
        int bufferLength = 4096;
        long int buffer[bufferLength];
        int k;
        for (k = 0; k < length; k++)
        {
            ids[k] = strtol(argv[k+1], NULL, 10);
        }
        long int total = ndb_intersect(ids, length, buffer, bufferLength);
        int i = 0;
        while (i < length && i < total)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%ld", buffer[i]);
            i++;
        }
        printf("\n");
    }

    return(0);
}
