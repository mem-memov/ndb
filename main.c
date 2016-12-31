#include "Node.h"
#include "File.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    //printf("Command: %s\n", argv[0]);

    char unitSizeInBytes = 6;
    char * path = "data";

    if (1 == argc) {
        struct File * file = File_construct(path, unitSizeInBytes);
        struct Node * node = Node_create(file);
        printf("%ld", Node_id(node));
        Node_destruct(node);
        File_destruct(file);
        return(0);
    }

    if (2 == argc) {
        long int nodeId = strtol(argv[1], NULL, 10);
        struct File * file = File_construct(path, unitSizeInBytes);
        struct Node * node = Node_read(file, nodeId);
        long int externalNodeCount = Node_count(node);
        long int i;
        for (i = 0; i < externalNodeCount; i++) {
            printf("%ld ", Node_ids(node, i));
        }
        Node_destruct(node);
        File_destruct(file);
        return(0);
    }

    if (3 == argc) {
        long int fromNodeId = strtol(argv[2], NULL, 10);
        long int toNodeId = strtol(argv[3], NULL, 10);
        struct File * file = File_construct(path, unitSizeInBytes);
        struct Node * fromNode = Node_read(file, toNodeId);
        Node_connect(unitSizeInBytes, path, fromNode, toNodeId);
        Node_destruct(fromNode);
        File_destruct(file);
        return(0);
    }

    return(1);
}
