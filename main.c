#include "ndb.h"
#include <stdio.h>
#include <string.h>

static void printIds(long int  * buffer, int commandIdCount, long int total);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Node Database commands:\n");
        printf(" ndb create\n");
        printf(" ndb read my_id\n");
        printf(" ndb connect my_from_id my_to_id\n");
        printf(" ndb intersect my_id_1 my_id_2 ...\n");
        printf(" ndb union my_id_1 my_id_2 ...\n");
        printf(" ndb difference my_id_1 my_id_2 ...\n");
        printf(" ndb insiders my_container_id my_id_1 my_id_2 ...\n");
        printf(" ndb outsiders my_container_id my_id_1 my_id_2 ...\n");
        printf("To view the file:\n");
        printf(" xxd -b data | more\n");
        printf("Source code:");
        printf(" https://github.com/mem-memov/ndb\n");
        return (0);
    }

    char command[32];
    strcpy(command, argv[1]);
    int commandIdCount = argc - 2;
    long int commandIds[commandIdCount];
    int k;
    for (k = 0; k < commandIdCount; k++)
    {
        commandIds[k] = strtol(argv[k+2], NULL, 10);
    }

    if (strcmp(command, "create") == 0)
    {
        long int nodeId = ndb_create();
        printf("%ld\n", nodeId);
    }

    if (strcmp(command, "read") == 0)
    {
        long int nodeId = commandIds[0];
        int bufferLength = 4096;
        long int buffer[bufferLength];
        long int total = ndb_read(nodeId, buffer, bufferLength);
        printIds(buffer, bufferLength, total);
    }

    if (strcmp(command, "connect") == 0)
    {
        long int fromNodeId = commandIds[0];
        long int toNodeId = commandIds[1];
        ndb_connect(fromNodeId, toNodeId);
    }

    if (strcmp(command, "intersect") == 0)
    {
        int bufferLength = 4096;
        long int buffer[bufferLength];
        long int total = ndb_intersect(commandIds, commandIdCount, buffer, bufferLength);
        printIds(buffer, bufferLength, total);
    }

    if (strcmp(command, "union") == 0)
    {
        int bufferLength = 4096;
        long int buffer[bufferLength];
        long int total = ndb_union(commandIds, commandIdCount, buffer, bufferLength);
        printIds(buffer, bufferLength, total);
    }

    if (strcmp(command, "difference") == 0)
    {
        int bufferLength = 4096;
        long int buffer[bufferLength];
        long int total = ndb_difference(commandIds, commandIdCount, buffer, bufferLength);
        printIds(buffer, bufferLength, total);
    }

    if (strcmp(command, "insiders") == 0)
    {
        long int nodeId = commandIds[0];
        int bufferLength = 4096;
        long int buffer[bufferLength];
        long int total = ndb_insiders(nodeId, commandIds+1, commandIdCount-1, buffer, bufferLength);
        printIds(buffer, bufferLength, total);
    }

    if (strcmp(command, "outsiders") == 0)
    {
        long int nodeId = commandIds[0];
        int bufferLength = 4096;
        long int buffer[bufferLength];
        long int total = ndb_outsiders(nodeId, commandIds+1, commandIdCount-1, buffer, bufferLength);
        printIds(buffer, bufferLength, total);
    }

    return(0);
}

static void printIds(long int  * buffer, int bufferLength, long int total)
{
    int i = 0;
    while (i < bufferLength && i < total)
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
