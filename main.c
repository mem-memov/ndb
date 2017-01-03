#include "Database.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 1 || argc > 3) {
        return(1);
    }

    char unitSizeInBytes = 6;
    char * path = "data";
    struct Database * database = Database_construct(path, unitSizeInBytes);

    if (1 == argc) {
        Database_createNode(database);
    }

    if (2 == argc) {
        long int nodeId = strtol(argv[1], NULL, 10);
        Database_readNode(database, nodeId);
    }

    if (3 == argc) {
        long int fromNodeId = strtol(argv[1], NULL, 10);
        long int toNodeId = strtol(argv[2], NULL, 10);
        Database_connectNodes(database, fromNodeId, toNodeId);
    }

    Database_destruct(database);
    return(0);
}
