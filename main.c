#include "Node.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    //printf("Command: %s\n", argv[0]);

    char unitSizeInBytes = 6;
    char * path = "data";

    if (1 == argc) {
        struct Node * node = Node_create(unitSizeInBytes, path);
        printf("%ld", Node_id(node));
        Node_destruct(node);
        return(0);
    }

    return(1);
}
